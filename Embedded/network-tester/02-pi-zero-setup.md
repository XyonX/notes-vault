

💡 On iPhones sometimes APs on 2.4 GHz might take a few seconds to appear, or you can **manually add the network** using:

- SSID: `PiZeroAP`
    
- Security: WPA2
    
- Password: `Portable123`

sudo nano /etc/mosquitto/mosquitto.conf
 and add this two line 

listener 1883

allow_anonymous true
# Pi Zero — Portable Hotspot + MQTT (Setup Notes)

**Purpose:** portable system where the Raspberry Pi Zero acts as the central hotspot + MQTT broker for multiple ESP32 devices and a Wio Terminal (ESP32s publish JSON scan data; Wio subscribes/display).

These notes record exactly what we did, why, and the commands/configs used so you can reproduce or troubleshoot later. Drop this file into Obsidian or any markdown viewer.

---

## Hardware / Software

- **Hardware:** Raspberry Pi Zero W (internal Wi‑Fi), ESP32-S3 devices, Wio Terminal, laptop, mobile hotspot (for initial connectivity).
    
- **OS:** Raspberry Pi OS Lite (32-bit, Bookworm).
    
- **Services / packages used:** `hostapd` (AP), `systemd-networkd` (static IP + DHCPServer), `dnsmasq` (optional — ended up disabled due to conflict), `mosquitto` (MQTT broker), `ssh` enabled for headless access.
    

---

## High-level decisions / reasoning

- Use **Pi Zero as AP + MQTT broker** (simple single-device portable network).
    
- Use `systemd-networkd` DHCPServer (Bookworm) rather than `dhcpcd` or `dnsmasq` to avoid conflicts and keep configuration minimal.
    
- `hostapd` handles the Wi‑Fi AP.
    
- `mosquitto` handles MQTT (TCP 1883) with username/password.
    
- Keep the AP local-only (no internet routing) for reliability and simplicity.
    
- Keep USB‑Ethernet gadget (g_ether) option for headless setup via USB when needed (we configured `config.txt` + `cmdline.txt`).
    

---

## Files we edited / created (summary)

- `/boot/config.txt` → add `dtoverlay=dwc2` for USB gadget support.
    
- `/boot/cmdline.txt` → add `modules-load=dwc2,g_ether` after `rootwait` and **remove** `console=serial0,115200` to avoid USB gadget flapping. (Keep `cmdline.txt` as a single line.)
    
- `/etc/systemd/network/08-wlan0.network` → static IP & `DHCPServer=yes` for AP network.
    
- `/etc/hostapd/hostapd.conf` → hostapd AP configuration (SSID, passphrase, channel, etc.).
    
- `/etc/default/hostapd` → `DAEMON_CONF` pointing to `/etc/hostapd/hostapd.conf`.
    
- `/etc/mosquitto/conf.d/50-local.conf` → simple mosquitto listener with `allow_anonymous false` + `password_file`.
    
- `/etc/mosquitto/passwd` → mosquitto username/password (created via `mosquitto_passwd`).
    
- (Optional) `/etc/dnsmasq.conf` — we tried but disabled because `systemd-networkd` already provided DHCP.
    

---

## Exact key config snippets (copy/paste)

### USB gadget (boot partition edits)

**/boot/config.txt** (append):

```
dtoverlay=dwc2
```

**/boot/cmdline.txt** (single line; insert after `rootwait`):

```
... rootwait modules-load=dwc2,g_ether quiet splash plymouth.ignore-serial-consoles cfg80211.ieee80211_regdom=IN
```

_Remove any `console=serial0,115200` entry to avoid COM3 ↔ RNDIS flapping._

---

### systemd network file (static IP + internal DHCP)

**/etc/systemd/network/08-wlan0.network**

```
[Match]
Name=wlan0

[Network]
Address=192.168.50.1/24
DHCPServer=yes
```

This assigns Pi IP `192.168.50.1` and provides DHCP to clients on `wlan0`.

---

### hostapd config

**/etc/hostapd/hostapd.conf**

```
interface=wlan0
driver=nl80211
ssid=PiZeroAP
hw_mode=g
channel=6
wmm_enabled=0
auth_algs=1
ignore_broadcast_ssid=0   # 0 = broadcast visible
wpa=2
wpa_passphrase=Portable123
wpa_key_mgmt=WPA-PSK
rsn_pairwise=CCMP
```

Point hostapd to this config with `/etc/default/hostapd`:

```
DAEMON_CONF="/etc/hostapd/hostapd.conf"
```

---

### Mosquitto simple config

Create password and config:

```bash
sudo mosquitto_passwd -c /etc/mosquitto/passwd mqttuser   # enter password
sudo tee /etc/mosquitto/conf.d/50-local.conf > /dev/null <<'EOF'
listener 1883
allow_anonymous false
password_file /etc/mosquitto/passwd
EOF



Enable and start mosquitto:

```bash
sudo systemctl enable mosquitto
sudo systemctl start mosquitto
```

---

## Key commands used (start/stop/restart/status)

```bash
# enable SSH on first boot: create empty file on /boot named 'ssh'
# start/enable services
sudo systemctl unmask hostapd
sudo systemctl enable hostapd
sudo systemctl start hostapd
sudo systemctl enable systemd-networkd
sudo systemctl restart systemd-networkd
sudo systemctl restart hostapd

# verify
sudo systemctl status hostapd
ip addr show wlan0
networkctl status wlan0
sudo systemctl status dnsmasq   # should be disabled in this setup
sudo systemctl status mosquitto

# bring wlan0 down/up & set IP manually (debug)
sudo ip link set wlan0 down
sudo ip addr flush dev wlan0
sudo ip addr add 192.168.50.1/24 dev wlan0
sudo ip link set wlan0 up

# USB gadget: load/unload modules
sudo modprobe g_ether
sudo modprobe -r g_serial g_multi
# blacklist serial gadget if needed
echo -e "blacklist g_serial\nblacklist g_multi" | sudo tee /etc/modprobe.d/disable-gserial.conf

# view logs (helpful)
sudo journalctl -u hostapd -b
sudo journalctl -xeu dnsmasq.service
```

---

## Troubleshooting notes (what we saw & fixes)

- **USB COM3 ↔ RNDIS flapping**: caused by `console=serial0,115200` + USB gadget modules. Fix: remove `console=serial0,115200` from `/boot/cmdline.txt` and add `modules-load=dwc2,g_ether`. If floppy persists, blacklist `g_serial`/`g_multi` and `modprobe g_ether` manually.
    
- **dnsmasq failed with `Address already in use`**: that happened because `systemd-networkd` DHCPServer was active. Solution: either use systemd's DHCPServer (preferred on Bookworm) or disable DHCPServer in systemd and let dnsmasq manage DHCP. We chose systemd-networkd and disabled dnsmasq.
    
- **Hostapd running but SSID not visible**: often caused by the interface still acting as a client on another network. Fix: ensure `wlan0` is not connected as station (stop `wpa_supplicant` or remove client networks), assign static IP for AP (`192.168.50.1`), restart hostapd.
    
- **First-boot `ssh` file disappears**: expected — OS deletes it after enabling SSH. No need to recreate.
    
- **If AP not starting**: run `sudo journalctl -u hostapd -b` and `ip addr show wlan0` to check if hostapd could bind to the interface.
    

---

## Example quick workflow (one-shot to make Pi an AP + MQTT broker)

Run these (copy/paste) on a clean Raspberry Pi OS Lite (after enabling SSH):

```bash
# update
sudo apt update && sudo apt upgrade -y
sudo apt install -y hostapd mosquitto mosquitto-clients

# USB gadget (if you want USB-ethernet access)
# add dtoverlay=dwc2 to /boot/config.txt and modules-load=dwc2,g_ether to /boot/cmdline.txt (after rootwait)

# networkd .network file
sudo tee /etc/systemd/network/08-wlan0.network > /dev/null <<'EOF'
[Match]
Name=wlan0

[Network]
Address=192.168.50.1/24
DHCPServer=yes
EOF

# hostapd
sudo tee /etc/hostapd/hostapd.conf > /dev/null <<'EOF'
interface=wlan0
driver=nl80211
ssid=PiZeroAP
hw_mode=g
channel=6
wmm_enabled=0
auth_algs=1
ignore_broadcast_ssid=0
wpa=2
wpa_passphrase=Portable123
wpa_key_mgmt=WPA-PSK
rsn_pairwise=CCMP
EOF
sudo tee /etc/default/hostapd > /dev/null <<'EOF'
DAEMON_CONF="/etc/hostapd/hostapd.conf"
EOF

# enable services
sudo systemctl unmask hostapd
sudo systemctl enable hostapd
sudo systemctl restart systemd-networkd
sudo systemctl restart hostapd

# mosquitto
sudo mosquitto_passwd -c /etc/mosquitto/passwd mqttuser
sudo tee /etc/mosquitto/conf.d/50-local.conf > /dev/null <<'EOF'
listener 1883
allow_anonymous false
password_file /etc/mosquitto/passwd
EOF
sudo systemctl enable mosquitto
sudo systemctl start mosquitto

# verify
ip addr show wlan0
networkctl status wlan0
sudo systemctl status hostapd
sudo systemctl status mosquitto
```

---

## How ESP32 / Wio should connect

- SSID: `PiZeroAP`
    
- Password: `Portable123`
    
- MQTT broker: `192.168.50.1:1883` with username `mqttuser` and the password you set with `mosquitto_passwd`.
    

Example topics: `scanner/<device-id>/results` or `scanner/results` for aggregated.

---

## What to do if you want the Pi also to have Internet while acting as AP

- Use a second Wi‑Fi adapter (USB dongle): `wlan0` = AP, `wlan1` = client to mobile Wi‑Fi.
    
- Or connect Pi to a phone hotspot (not both at once on the same radio).
    

---

## Useful debug commands

- `sudo journalctl -u hostapd -b`
    
- `sudo journalctl -xeu dnsmasq.service`
    
- `ip addr show wlan0`
    
- `networkctl status wlan0`
    
- `lsmod | egrep "g_ether|g_serial|g_multi"`
    
- `sudo systemctl status mosquitto`
    

---

## Final notes

Keep the configs and credentials secure. If you plan to expose this network to any untrusted environment, consider enabling TLS for MQTT and stronger WPA2PSK passphrases. For many ESP32 clients and a Wio Terminal, this lightweight Pi Zero hub setup works reliably for a handful of devices.

_End of note._