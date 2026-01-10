# C++ Casting Operators

In C++ there are **four main casting operators**, each with a different purpose and set of rules.
We'll go step-by-step so you can see *why* each exists, how it behaves, and when you'd use it.

## 1. `static_cast`

**Purpose:**

* Used for conversions that are known at *compile time* and are considered *safe* by the programmer.
* Commonly used for:

  * Converting between related types in inheritance (but *only downcast if you're sure* the object is of that type).
  * Numeric type conversions (`int` → `double`, etc.).
  * Removing `const`-ness (but only with care).

**Key points:**

* Checked **at compile time** (no runtime check).
* Dangerous if you downcast to the wrong type — the compiler won't stop you, but the program can behave unpredictably.

**Example:**

```cpp
class Base { };
class Derived : public Base { };

Base* b = new Derived();
Derived* d = static_cast<Derived*>(b); // Works, but unsafe if b isn't actually Derived.
```

## 2. `dynamic_cast`

**Purpose:**

* Used for *safe* type conversions **within a class hierarchy**.
* Performs a **runtime check** to ensure the cast is valid.
* Works only on pointers and references to polymorphic classes (must have at least one `virtual` function).

**Key points:**

* If cast fails:

  * For pointers: returns `nullptr`.
  * For references: throws `std::bad_cast`.
* Slightly slower than `static_cast` because it uses RTTI (Run-Time Type Information).
* Safer for downcasting in inheritance hierarchies.

**Example:**

```cpp
class Base { public: virtual ~Base() {} };
class Derived : public Base { };

Base* b = new Base();
Derived* d = dynamic_cast<Derived*>(b); // returns nullptr, because b isn't Derived
```

## 3. `const_cast`

**Purpose:**

* Used to **add or remove `const` or `volatile` qualifiers**.
* Commonly used to call functions that incorrectly lack `const` in their parameter list, or to work with legacy APIs.

**Key points:**

* Does **not** change the actual object in memory — only removes the compiler's protection.
* If you try to modify an object that was originally declared `const`, behavior is **undefined**.

**Example:**

```cpp
void printMessage(char* msg) { /* ... */ }

const char* text = "Hello";
printMessage(const_cast<char*>(text)); // Removes const
```

## 4. `reinterpret_cast`

**Purpose:**

* Used for **low-level reinterpreting** of bit patterns — essentially telling the compiler "treat this memory as if it were of another type."
* Commonly used in:

  * Converting between unrelated pointer types.
  * Casting integral types to pointers (and vice versa).

**Key points:**

* Very dangerous — no checks, no type-safety.
* Often used in systems programming, networking, or when interfacing with hardware.

**Example:**

```cpp
int a = 65;
char* p = reinterpret_cast<char*>(&a); // Treats int's memory as char[]
```

## Quick Summary Table

| Cast Type          | Checks at Compile Time? | Checks at Run Time? | Main Use Case                                                  | Safety Level               |
| ------------------ | ----------------------- | ------------------- | -------------------------------------------------------------- | -------------------------- |
| `static_cast`      | ✅ Yes                   | ❌ No                | Type-safe, known conversions; base ↔ derived (safe if correct) | Medium                     |
| `dynamic_cast`     | ✅ Yes                   | ✅ Yes               | Safe downcasting in polymorphic hierarchies                    | High                       |
| `const_cast`       | ✅ Yes                   | ❌ No                | Add/remove const/volatile qualifiers                           | Medium (danger if misused) |
| `reinterpret_cast` | ✅ Yes                   | ❌ No                | Bit-level reinterpreting of memory                             | Low (dangerous)            |