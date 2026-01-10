# FUNDAMENTAL OF PROGRAMING - 01
1. Data Types & Variables
\t•\tPrimitive vs. non-primitive data types (int, float, char, bool, string)
\t•\tSize of data types in memory (sizeof in C/C++, sys.getsizeof() in Python)
\t•\tSigned vs. unsigned integers
\t•\tType conversion (implicit/explicit casting)
\t•\tOverflow/underflow behavior


## **Tricky Data Types & Variables — MCQ Revision Notes (C/C++)**

---

### **1. Size of Character Literals**

```c
printf("%zu", sizeof('A'));
```

* `'A'` in C is an **`int` literal**, not `char`.
* `sizeof('A')` → `sizeof(int)` (usually **4 bytes**).
* ✅ **Answer:** `4` (on most modern systems).

---

### **2. Signed vs. Unsigned Conversion**

```c
unsigned int x = -1;
printf("%u", x);
```

* `-1` converted to unsigned → wraps to **max unsigned value**.
* On 32-bit: `4294967295`.
* ✅ **Tip:** Negative → unsigned = wraparound.

---

### **3. Integer Overflow Wraparound**

```c
short x = 32767; // max signed short
x = x + 1;
printf("%d", x);
```

* Exceeding max value → wraps (Two’s complement).
* Result: **-32768**.
* ✅ Overflow in signed integers is *undefined in C standard*, but most compilers wrap.

---

### **4. Integer Division + Wrong Format Specifier**

```c
int a = 5, b = 2;
printf("%f", a / b);
```

* `a / b` = integer division → `2`.
* `%f` expects `double` → mismatch = **Undefined Behavior** (may print `2.000000` or garbage).
* ✅ **Rule:** Format specifier must match type.

---

### **5. Float vs. Double Precision**

```c
double d = 0.1;
if (d == 0.1f) ...
```

* `0.1f` (float) has less precision than `0.1` (double).
* Comparison usually **fails**.
* ✅ **Rule:** Be cautious when comparing `float` & `double`.

---

### **6. Signed vs. Unsigned `char`**

```c
char ch = 255;
printf("%d", ch);
```

* If `char` is **signed** → `-1`.
* If `char` is **unsigned** → `255`.
* ✅ **Rule:** `char` signedness is **implementation-defined**.

---

### **7. Modifying a Const Variable**

```c
const int x = 5;
int *p = (int*)&x;
*p = 10;
printf("%d", x);
```

* Modifying `const` via pointer = **Undefined Behavior**.
* Might print `5` or `10` depending on compiler.
* ✅ **Rule:** Don't cast away `const` unless very sure.

---

### **8. Global Variable Redefinition**

```c
int x = 5;
...
int x = 10; // same file
```

* Two globals with same name in same scope → **Compiler Error**.

---

### **9. Uninitialized Local Variables**

```c
int x;
printf("%d", x);
```

* Local variables are **not** auto-initialized.
* Value = garbage.

---

### **10. Enum as Int**

```c
enum week {MON, TUE, WED};
enum week day = 10;
```

* Enum in C behaves like `int`. Any integer assignment is valid.

---

✅ **Key MCQ Survival Rules:**

1. **Always check implicit type conversions** — especially signed ↔ unsigned.
2. **Watch for format specifier mismatches** — leads to undefined behavior.
3. **Remember char literal size trap** — `'A'` is `int` in C.
4. **Beware float/double comparisons** — precision bites.
5. **Know implementation-defined behaviors** — char signedness, integer overflow handling.

---

If you want, I can now **expand this into a 40-question “Data Types & Variables Trap Bank”** mixing easy, medium, and sneaky ones — perfect for MCQ speed drills. That way you’ll have *zero hesitation* in the real test.