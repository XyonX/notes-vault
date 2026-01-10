# OOP Instance Storage and Pointer

## Class Setup

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    int x = 10;
    virtual void show() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    int y = 20;
    void show() override { cout << "Derived\n"; }
};
```

## Scenario 1: Create Base → Store in Base pointer ✅ Safe

```cpp
Base* b = new Base;
b->show(); // Base
// Only Base members accessible
delete b;
```

* **Safe**: Exact match of type and pointer.
* **Memory size**: only `Base`.

## Scenario 2: Create Base → Store in Derived pointer ❌ Unsafe

```cpp
// Derived* d = new Base; // ❌ Compile error (needs explicit cast)
Derived* d = (Derived*) new Base; // Forced cast - very unsafe!
d->show(); // Undefined behavior (pretending Base is Derived)
delete d;  // Likely crash
```

* **Danger**: Base doesn't have `y`, but we pretend it does — memory corruption risk.
* **C++**: Will not allow implicit assignment, but C-style cast bypasses the check.

## Scenario 3: Create Derived → Store in Derived pointer ✅ Safe

```cpp
Derived* d = new Derived;
d->show(); // Derived
cout << d->y; // OK
delete d;
```

* **Safe**: Exact match again.
* **Memory size**: includes Base + Derived parts.

## Scenario 4: Create Derived → Store in Base pointer ✅ Safe (with limits)

```cpp
Base* b = new Derived;
b->show(); // Derived (polymorphism)
cout << b->x; // OK
// b->y; // ❌ Not accessible (pointer type is Base)
delete b;
```

* **Reason**: Useful for polymorphism (e.g., passing `Derived` to a function expecting `Base*`).
* **Memory**: Still allocates full Derived object, but Base pointer only sees Base interface.

## Casting Back

```cpp
Base* b = new Derived;

// ✅ Safe if it really points to Derived
Derived* d1 = dynamic_cast<Derived*>(b);
if (d1) cout << d1->y;

// ❌ Unsafe if it doesn't actually point to Derived
Base* b2 = new Base;
Derived* d2 = dynamic_cast<Derived*>(b2); // returns nullptr
```

* **`static_cast`**: Checks at compile time, no runtime safety.
* **`dynamic_cast`**: Checks at runtime, returns `nullptr` if wrong type (only works with polymorphic types — i.e., classes with `virtual`).