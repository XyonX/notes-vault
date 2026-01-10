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