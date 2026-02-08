def my_decorator(func):   # decorator is just a function
    def wrapper():
        print("Before")
        func()
        print("After")
    return wrapper        # ← THIS creates the decorator object

@my_decorator
def greet():
    print("Hello")


greet = my_decorator(greet)


Perfect timing for this question 😄 — now we go **one level deeper**.

You’re basically asking **two things**:

1. **How is a decorator object created?**
2. **How does a decorator work when it itself takes parameters?**

Let’s go step-by-step, slow and visual 🧠👇

---

## 1️⃣ How a decorator object is created (no parameters)

### Normal function

```python
def greet():
    print("Hello")
```

### Decorator

```python
def my_decorator(func):   # decorator is just a function
    def wrapper():
        print("Before")
        func()
        print("After")
    return wrapper        # ← THIS creates the decorator object
```

### When you write:

```python
@my_decorator
def greet():
    print("Hello")
```

Python actually does this internally:

```python
greet = my_decorator(greet)
```

### What happened?

* `greet` (function object) passed to `my_decorator`
* `wrapper` function is **created**
* `wrapper` is **returned**
* `greet` now **references wrapper**

📌 **The decorator object = the returned `wrapper` function**

---

## 2️⃣ Now: Decorator WITH parameters (important)

Syntax looks scary at first:

```python
@decorator(param)
def func():
    ...
```

But calm — it’s just **functions returning functions** 😌

---

## 3️⃣ Example: Decorator with parameter

### Goal:

Print a custom message before function runs.

---

### Step 1: Outer function (takes decorator parameter)

```python
def my_decorator(message):
```

This runs **FIRST**.

---

### Step 2: Actual decorator (takes function)

```python
    def decorator(func):
```

This runs **SECOND**.

---

### Step 3: Wrapper (wraps function)

```python
        def wrapper():
            print(message)
            func()
        return wrapper
    return decorator
```

---

### Full code 👇

```python
def my_decorator(message):        # 1️⃣ decorator parameter
    def decorator(func):         # 2️⃣ function to decorate
        def wrapper():           # 3️⃣ wrapper
            print(message)
            func()
        return wrapper
    return decorator
```

---

### Using it

```python
@my_decorator("Starting function")
def greet():
    print("Hello")
```

### Python internally does:

```python
decorator_obj = my_decorator("Starting function")
greet = decorator_obj(greet)
```

---

### Calling the function

```python
greet()
```

Output:

```
Starting function
Hello
```

---

## 🔁 Execution order (VERY IMPORTANT)

When Python sees this:

```python
@my_decorator("Starting function")
def greet():
    ...
```

Order is:

1️⃣ `my_decorator("Starting function")`
→ returns `decorator`

2️⃣ `decorator(greet)`
→ returns `wrapper`

3️⃣ `greet = wrapper`

4️⃣ `greet()`
→ runs `wrapper()`

---

## One-line mental model 🧠

> **Decorator with parameters = function → decorator → wrapper**

OR

> **Three layers: config → function → execution**

---

## Exam-ready explanation ✍️

> When a decorator has parameters, an outer function first captures the parameters and returns the actual decorator, which then receives the function and returns a wrapper function.

---

If you want, next we can:

* Add `*args, **kwargs`
* Show **Flask route decorator internally**
* Or do a **diagram-style explanation**

Just say 👍



