Sure! Here’s a neatly structured **Obsidian note** you can use for this concept:

---

# Integer Promotion & 1LL Trick in C++

## 1. Problem

When multiplying large integers in C++, the **result type depends on the operands**, not on the variable you assign to.

```cpp
int a = 1e9;
int b = 2e9;
long long sum = a * b; // ❌ overflow! a*b computed as int first
```

- Even though `sum` is `long long`, `a * b` is computed as `int` first → **overflow occurs before assignment**.
    

---

## 2. The 1LL Trick

- `1LL` is a **long long literal**: number `1` of type `long long`.
    
- Multiplying by it **promotes the entire expression to long long**:
    

```cpp
long long sum = 1LL * a * b; // ✅ safe
```

- Steps:
    
    1. `1LL * a` → `a` promoted to long long
        
    2. Multiply by `b` (int promoted to long long) → safe 64-bit result
        

> `LL` is a **suffix** for literals only. You **cannot** put `LL` on a variable.

---

## 3. Using a long long variable instead of 1LL

```cpp
long long factor = 1;
long long sum = factor * a * b; // ✅ safe
```

- Works the same as `1LL`
    
- Important: **factor must appear in the first multiplication** to prevent overflow.
    

---

## 4. Order Matters

```cpp
long long sum1 = factor * a * b; // ✅ safe
long long sum2 = a * b * factor; // ❌ may overflow
```

- `a * b` computed first → int overflow → multiplying by factor is too late
    
- Always include a `long long` operand **at the start** of the multiplication
    

---

## 5. Comparison with Floating Point

- Float/double arithmetic automatically promotes smaller types:
    

```cpp
float x = 1e20f;
double y = 1e20;
double z = x + y; // ✅ x promoted to double automatically
```

- No need for 1LL-like trick for floats.
    

---

## 6. TL;DR / Rules of Thumb

|Scenario|Safe way|Notes|
|---|---|---|
|int * int → long long|`1LL * a * b`|Must include 64-bit operand first|
|int * long long → long long|`factor * a`|Implicit promotion|
|float * double → double|`x + y`|Automatic promotion|

---

You can **attach this note in Obsidian** under “C++ Tips” or “Integer Arithmetic Gotchas” for reference.

---

If you want, I can also **add a tiny diagram showing “step-by-step multiplication & promotion”** for Obsidian — it looks really clean visually.

Do you want me to do that?