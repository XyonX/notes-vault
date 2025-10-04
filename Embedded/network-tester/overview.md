Nice — let’s build a portable **Network Scanner / Tester** that uses all three devices (XIAO‑ESP32‑S3, Raspberry Pi Zero, and Wio Terminal) powered from your 20 k mAh power bank. I’ll give you a full, ready-to-build blueprint: hardware list, network / data flows, safe/legal notes, step‑by‑step setup, finished wiring/power plan, and copy‑paste code for each device (ESP32 scanner, Pi aggregator + web dashboard, Wio Terminal display client). I’ll also include example outputs and troubleshooting tips so you can get it running now.

> Important legal note: this project performs passive/active **network discovery and scanning only** (SSID/BSSID, RSSI, device presence, BLE advertisements). **Do not** attempt unauthorized access, deauthentication, MITM, or any intrusive attacks. Use only on networks/devices you own or have explicit permission to test.

---

# 1 — What the system will do (high level)

- **ESP32‑S3 (XIAO)**: continuously scan surrounding **Wi‑Fi APs** and **BLE advertisements**. Package results and publish as JSON to an MQTT broker (or HTTP) over Wi‑Fi.
    
- **Raspberry Pi Zero**: runs an MQTT broker + aggregator + lightweight web server. Receives ESP32 scan telemetry, stores logs (SQLite), serves a dashboard (HTML/JS) you can open from phone or laptop on the local hotspot created by Pi (or via Wi‑Fi). Also can run extra scans itself (Pi Wi‑Fi adapter) if wanted.
    
- **Wio Terminal** (optional): subscribes to MQTT and displays live scan list (visual) — portable display for immediate view.
    
- **Power**: all three devices powered from the 20k power bank via USB. Mac/iPhone can also connect to the Pi AP or view the Pi web-dashboard.
    

Flow: `ESP32 → Wi‑Fi → MQTT → Pi (store + dashboard)` and `Wio Terminal ← MQTT ← Pi` (or Wio may connect to same broker directly).

---

# 2 — Hardware checklist

- Seeed Studio XIAO ESP32‑S3 (USB‑C) — 1
    
- Raspberry Pi Zero (W recommended for built‑in Wi‑Fi) — 1
    
    - microSD card 16GB+ (Raspberry Pi OS Lite or Raspberry Pi OS)
        
- Wio Terminal (with USB cable) — 1 (optional — for local display)
    
- 20,000 mAh power bank(s) with 2–3 simultaneous USB outputs (or use a USB hub + power bank)
    
- USB‑A/C cables (for powering each device). If Pi Zero uses micro USB OTG power, ensure correct cable.
    
- MicroSD adapter for Pi
    
- (Optional) small USB Wi‑Fi adapter for Pi if using Pi Zero (non‑W), for better scanning
    
- (Optional) small Li‑Po + battery management if you want internal battery
    
- Breadboard & jumper wires only if adding external sensors
    

---

# 3 — Power plan & battery runtime (practical)

- All three devices draw different currents:
    
    - ESP32 S3 while scanning: ≈ 80–200 mA (depends on TX). In light duty scanning, average ~100 mA.
        
    - Raspberry Pi Zero W: 150–300+ mA idle; up to 400–500 mA under load.
        
    - Wio Terminal: ~120–200 mA while display active.
        
- With a 20,000 mAh bank (nominal 5V output ≈ 12,000 mAh effective after conversion), realistic runtime rough estimate:
    
    - Combined ~400–800 mA → ~15–30 hours. (This is an approximation; depends on power bank efficiency and active CPU usage.)
        
- To extend battery life: put ESP32 into duty cycles (scan every N seconds), have Pi sleep (or reduce dashboard polling), dim Wio display.
    

---

# 4 — Software architecture & components

- **ESP32 (firmware)**:
    
    - Wi‑Fi scan (list SSID, BSSID, RSSI, channel, auth) using Arduino core or ESP-IDF.
        
    - BLE scan (advertising, MAC, RSSI, adv data summary).
        
    - Publish JSON to MQTT topic `network/scanner/<esp_id>/scan`.
        
    - Optional: serve a small HTTP endpoint for manual scan on demand.
        
- **Raspberry Pi Zero**:
    
    - Install `mosquitto` (MQTT broker), `python3`, `paho‑mqtt`, `flask` (or `fastapi`), `sqlite3`.
        
    - Subscriber script writes incoming JSON to SQLite, optionally stores hourly CSV.
        
    - Flask web UI to show live list (websocket or polling) and historical logs. Optionally serve Pi as a Wi‑Fi AP so phone/Mac can connect.
        
- **Wio Terminal**:
    
    - Program using Arduino or Mbed OS. MQTT client subscribes to `network/scanner/+/scan` and shows recent scan list on screen. Buttons to switch sort (RSSI/SSID).
        

---

# 5 — ESP32 code (Arduino style) — Wi‑Fi + BLE scan + MQTT publish

You can compile this in Arduino IDE (install ESP32 board package). Replace `WIFI_SSID`, `WIFI_PASS`, and `MQTT_SERVER` with your values. This example uses `PubSubClient` for MQTT.

```cpp
// ESP32_Scanner.ino
#include <WiFi.h>
#include <PubSubClient.h>
#include "BLEDevice.h"
#include <ArduinoJson.h>

const char* WIFI_SSID = "YourSSID";
const char* WIFI_PASS = "YourPass";
const char* MQTT_SERVER = "192.168.4.1"; // Pi IP or broker IP
const int MQTT_PORT = 1883;
const char* ESP_ID = "esp32s3_01";

WiFiClient espClient;
PubSubClient client(espClient);

// scan interval (ms)
const unsigned long SCAN_INTERVAL = 10000;
unsigned long lastScan = 0;

// BLE scanning callback
class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice advertisedDevice) {
    // Not used here - we'll poll results after start
  }
};

void connectWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  unsigned long t = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - t < 20000) {
    delay(200);
  }
}

void reconnectMQTT() {
  while (!client.connected()) {
    if (client.connect(ESP_ID)) {
      // connected
    } else {
      delay(1000);
    }
  }
}

void doWifiScanAndPublish() {
  int n = WiFi.scanNetworks(true, true); // async=true? if not supported use synchronous
  // Wait for results if async omitted
  delay(2000);
  n = WiFi.scanNetworks();
  StaticJsonDocument<4096> doc;
  JsonArray wifiArr = doc.createNestedArray("wifi");
  for (int i = 0; i < n; ++i) {
    JsonObject ap = wifiArr.createNestedObject();
    ap["ssid"] = WiFi.SSID(i);
    ap["bssid"] = WiFi.BSSIDstr(i);
    ap["rssi"] = WiFi.RSSI(i);
    ap["channel"] = WiFi.channel(i);
    ap["enc"] = WiFi.encryptionType(i);
  }

  // BLE scan
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setActiveScan(true);
  BLEScanResults found = pBLEScan->start(3); // scan for 3 seconds
  JsonArray bleArr = doc.createNestedArray("ble");
  for (int i = 0; i < found.getCount(); ++i) {
    BLEAdvertisedDevice dev = found.getDevice(i);
    JsonObject obj = bleArr.createNestedObject();
    obj["addr"] = dev.getAddress().toString();
    obj["name"] = dev.getName().c_str();
    obj["rssi"] = dev.getRSSI();
  }
  doc["ts"] = millis();
  doc["id"] = ESP_ID;

  char buf[4096];
  size_t nbytes = serializeJson(doc, buf, sizeof(buf));
  client.publish(String("network/scanner/") + ESP_ID + "/scan", buf, nbytes);
  WiFi.scanDelete(); 
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  connectWiFi();
  client.setServer(MQTT_SERVER, MQTT_PORT);

  BLEDevice::init("");
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) connectWiFi();
  if (!client.connected()) reconnectMQTT();
  client.loop();

  if (millis() - lastScan > SCAN_INTERVAL) {
    doWifiScanAndPublish();
    lastScan = millis();
  }
}
```

Notes:

- Use `WiFi.scanNetworks()` synchronous variant for simplicity. You can adjust scan intervals.
    
- `encryptionType()` returns enum; you can map it to strings if needed.
    

---

# 6 — Raspberry Pi Zero setup (commands + Python)

## 6.1 Prepare Pi (Raspbian / Raspberry Pi OS)

1. Flash Raspberry Pi OS (Lite or Desktop) to microSD.
    
2. Boot Pi, complete initial setup, enable SSH if desired.
    
3. Install packages:
    

```bash
sudo apt update
sudo apt install -y mosquitto mosquitto-clients python3-pip sqlite3
pip3 install paho-mqtt flask flask-socketio
```

## 6.2 Simple Python subscriber (aggregator -> SQLite + console)

Save as `mqtt_aggregator.py`:

```python
# mqtt_aggregator.py
import sqlite3, json, time
import paho.mqtt.client as mqtt

DB = 'scans.db'
TOPIC = 'network/scanner/+/scan'

conn = sqlite3.connect(DB, check_same_thread=False)
c = conn.cursor()
c.execute('''CREATE TABLE IF NOT EXISTS scans
             (id TEXT, ts INTEGER, payload TEXT, recv_ts INTEGER)''')
conn.commit()

def on_connect(client, userdata, flags, rc):
    print("Connected rc=", rc)
    client.subscribe(TOPIC)

def on_message(client, userdata, msg):
    recv_ts = int(time.time())
    payload = msg.payload.decode('utf-8')
    # store raw payload
    c.execute("INSERT INTO scans (id, ts, payload, recv_ts) VALUES (?,?,?,?)",
              (msg.topic.split('/')[2], json.loads(payload).get('ts',0), payload, recv_ts))
    conn.commit()
    print("Saved", msg.topic, "len", len(payload))

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect('localhost', 1883, 60)
client.loop_forever()
```

Run it: `python3 mqtt_aggregator.py`

## 6.3 Simple Flask dashboard (serve latest entries)

Save as `app.py`:

```python
# app.py
from flask import Flask, jsonify, render_template_string
import sqlite3, json

app = Flask(__name__)
DB = 'scans.db'

@app.route('/latest')
def latest():
    conn = sqlite3.connect(DB)
    c = conn.cursor()
    c.execute("SELECT id, ts, payload, recv_ts FROM scans ORDER BY rowid DESC LIMIT 50")
    rows = c.fetchall()
    out = []
    for r in rows:
        try:
            payload = json.loads(r[2])
        except:
            payload = {}
        out.append({'id':r[0],'ts':r[1],'payload':payload,'recv':r[3]})
    return jsonify(out)

INDEX = """
<!doctype html>
<html>
<head>
<title>Portable Scanner Dashboard</title>
</head>
<body>
<h2>Latest Scans</h2>
<div id="list"></div>
<script>
async function load(){
  let r = await fetch('/latest');
  let data = await r.json();
  document.getElementById('list').innerHTML = '<pre>'+JSON.stringify(data,null,2)+'</pre>';
}
setInterval(load,3000);
load();
</script>
</body>
</html>
"""
@app.route('/')
def index():
    return render_template_string(INDEX)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
```

Run: `python3 app.py`

Open from your phone or Mac pointing to Pi IP: `http://<pi_ip>:5000/`

---

# 7 — Wio Terminal (display) code (Arduino / MQTT)

Wio Terminal supports `PubSubClient` or `ArduinoMqttClient`. Example with Arduino:

```cpp
// Wio_MQTT_Display.ino
#include <WiFi.h>
#include <PubSubClient.h>
#include <TFT_eSPI.h> // or the Seeed display lib

const char* ssid = "YourSSID";
const char* pass = "YourPass";
const char* mqttServer = "192.168.4.1";
WiFiClient wifiClient;
PubSubClient client(wifiClient);

TFT_eSPI tft = TFT_eSPI();
String lastMsg = "";

void callback(char* topic, byte* payload, unsigned int length) {
  String s;
  for (unsigned int i=0;i<length;i++) s += (char)payload[i];
  lastMsg = s;
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0,0);
  tft.setTextSize(1);
  tft.println(topic);
  tft.println(s.substring(0,300)); // show truncated JSON
}

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) delay(200);
  client.setServer(mqttServer, 1883);
  client.setCallback(callback);
  while (!client.connected()) {
    client.connect("wio_display");
    delay(500);
  }
  client.subscribe("network/scanner/+/scan");
}

void loop() {
  client.loop();
}
```

This draws the latest MQTT payload onto the screen. You can implement scroll, filtering, or parse the JSON for formatted display.

---

# 8 — Networking / connectivity details & options

- Option A: **Pi as MQTT broker (recommended)** — Pi runs mosquitto; ESP32 and Wio both connect to same Wi‑Fi (Pi either on same external network or Pi creates its own AP).
    
- Option B: **ESP32 connects to a home Wi‑Fi and publishes to an external cloud MQTT** (requires mobile data or internet).
    
- For fully offline portable usage: make Pi an **Access Point** (hostapd) + mosquitto. ESP32 and Wio connect to Pi AP and publish locally.
    
    - Pi AP steps (summary): install `hostapd` and `dnsmasq`, configure, set static IP (e.g., 192.168.4.1). Then set `MQTT_SERVER` to `192.168.4.1`.
        

---

# 9 — Putting it together — recommended deployment steps

1. **Prep Pi**: flash OS, enable Wi‑Fi, install mosquitto, run PI as AP if you want fully portable mode.
    
2. **Run aggregator**: start `mqtt_aggregator.py` and `app.py` on Pi and confirm Mosquitto is running (`mosquitto_sub -t '#' -v` to test).
    
3. **ESP32**: flash scanner sketch with `MQTT_SERVER` set to Pi IP. Power on; confirm device publishes to `network/scanner/esp32s3_01/scan`.
    
4. **Wio Terminal**: flash display client; subscribe to same topic.
    
5. **Power**: plug Pi, ESP32, and Wio into the power bank. If Pi uses more current and power bank has limited ports, ensure total current supported.
    
6. **Test**: open Pi dashboard on Mac/iPhone (connect to Pi AP), view live scans. Use `mosquitto_sub` to watch messages from ESP32 in terminal.
    

---

# 10 — Example JSON payload (what you’ll see)

```json
{
  "id": "esp32s3_01",
  "ts": 1234567890,
  "wifi": [
    {"ssid":"HomeNet","bssid":"aa:bb:cc:dd:ee:ff","rssi":-42,"channel":6,"enc":3},
    {"ssid":"CoffeeShop","bssid":"11:22:33:44:55:66","rssi":-78,"channel":11,"enc":0}
  ],
  "ble": [
    {"addr":"AA:BB:CC:11:22:33","name":"SensorTag","rssi":-62},
    {"addr":"11:22:33:44:55:66","name":"","rssi":-80}
  ],
  "recv_ts": 169xx...
}
```

---

# 11 — Advanced ideas & extensions

- Geotagging: add a GPS module or use phone GPS to map networks.
    
- Passive probe-sniffing: use monitor mode (requires special driver/hardware) — more advanced and more intrusive; don’t do without permission.
    
- Add file logging to SD (Wio or Pi).
    
- Use Pi to run offline ML/analysis (device classification by RSSI patterns).
    
- Auto‑alert: if a new unknown AP appears, send push notification via Pushover/IFTTT (requires internet).
    

---

# 12 — Troubleshooting tips

- If ESP32 doesn’t connect to Pi broker: ping the Pi IP from your laptop; check `mosquitto` logs (`sudo journalctl -u mosquitto`).
    
- If Wi‑Fi scanning returns few APs: ensure ESP32 Wi‑Fi mode is STA; try increasing scan time.
    
- If power bank shuts off due to low load, use a “load keep alive” (small USB load or enable power bank’s always‑on mode if available).
    
- For Pi Zero, heavy dashboard load can spike power consumption— keep it minimal or use Pi Zero 2 W for more CPU.
    

---

# 13 — Ready-to-run checklist (quick)

-  Pi flashed + mosquitto + aggregator + flask running
    
-  Pi AP configured (optional)
    
-  ESP32 sketch flashed with correct MQTT IP and Wi‑Fi creds
    
-  Wio Terminal sketch flashed (optional)
    
-  All devices connected to power bank
    
-  Phone/Mac connected to Pi AP or same network and open dashboard
    

---

If you want, I can:

- Generate the **exact hostapd/dnsmasq config** to make the Pi an AP.
    
- Produce a small **packaging sketch** showing how to physically mount devices and cables in a single portable case.
    
- Tune the **ESP32 scan interval and power‑saving code** to optimize runtime for your power bank.
    
- Create a **prebuilt SD image** (Pi) with mosquitto + aggregator + dashboard preinstalled (I can provide full shell script you run on Pi).
    

Which of those would you like next?