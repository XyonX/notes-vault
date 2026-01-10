# Composition vs Aggregation

## 1. Composition - Strong "has-a" relationship

* Contained object's lifetime is tied to the owner.
* When the owner is destroyed, the part is destroyed too.

```cpp
#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started\n";
    }
};

class Car {
private:
    Engine engine; // Composition: Engine is part of Car

public:
    void startCar() {
        engine.start();
        cout << "Car is moving!\n";
    }
};

int main() {
    Car myCar;       // Engine created automatically
    myCar.startCar();
    // Engine destroyed when myCar is destroyed
}
```

## 2. Aggregation - Weak "has-a" relationship

* The contained object is **passed in**; it's not owned.
* It can exist before and after the owner is destroyed.

```cpp
#include <iostream>
using namespace std;

class Engine {
public:
    void start() {
        cout << "Engine started\n";
    }
};

class Car {
private:
    Engine* engine; // Aggregation: Engine is linked, not owned

public:
    Car(Engine* eng) : engine(eng) {}

    void startCar() {
        engine->start();
        cout << "Car is moving!\n";
    }
};

int main() {
    Engine eng;         // Engine exists independently
    Car myCar(&eng);    // Pass existing Engine to Car

    myCar.startCar();
    // Engine still exists even if Car is destroyed
}
```

## Key Difference Table

| Feature             | Composition                 | Aggregation                     |
| ------------------- | --------------------------- | ------------------------------- |
| Object ownership    | Owner **owns** the part     | Owner **uses** the part         |
| Lifetime dependency | Part dies with owner        | Part can outlive owner          |
| Implementation      | Part is a **member object** | Part is a **pointer/reference** |

## Analogy

> Composition = *"My heart is part of me."*
> Aggregation = *"I have a phone, but I can change it anytime."*