Here’s a clean and structured Obsidian-style note for your vault, Joydip — focused on Python iterators, including the protocol, key methods, and a custom class implementation.

---

## 🧭 Python Iterator Protocol

### 🔹 What is an Iterator?

An **iterator** is an object that allows you to traverse through all the elements of a container, one at a time.

- Implements two special methods:
    - `__iter__()` → returns the iterator object itself
    - `__next__()` → returns the next value or raises `StopIteration`

### 🔹 What is an Iterable?

An **iterable** is any object that can return an iterator using `iter()`.

Common iterable types:

- `list`, `tuple`, `str`, `set`, `dict`, `range`, `file`, `generator`

---

## 🔧 Built-in Functions

### `iter(obj)`

Returns an iterator from an iterable object.

### `next(iterator)`

Returns the next item from the iterator. Raises `StopIteration` when exhausted.

---

## 🧪 Manual Iteration Example

```python
lst = [10, 20, 30]
it = iter(lst)

print(next(it))  # 10
print(next(it))  # 20
print(next(it))  # 30
print(next(it))  # ❌ Raises StopIteration
```

---

## 🛠️ Custom Iterator Class

### 🎯 Goal: Create an iterator that counts from 0 to a given limit

```python
class Counter:
    def __init__(self, limit):
        self.limit = limit
        self.current = 0

    def __iter__(self):
        return self  # Returns itself as the iterator

    def __next__(self):
        if self.current >= self.limit:
            raise StopIteration
        val = self.current
        self.current += 1
        return val
```

### 🔍 Usage

```python
c = Counter(3)
it = iter(c)

print(next(it))  # 0
print(next(it))  # 1
print(next(it))  # 2
print(next(it))  # ❌ StopIteration
```

---

## 🧩 Iterator vs Iterable vs Generator

|Concept|Can be looped?|Has `__next__()`?|Memory Efficient?|
|---|---|---|---|
|Iterable|✅|❌|Depends|
|Iterator|✅|✅|Often|
|Generator|✅|✅|✅ (lazy eval)|

---

## 🧠 Notes

- Iterators are **stateful** — they remember where they are.
- You can only loop through them **once** unless you recreate them.
- Use `try/except` with `next()` to avoid `StopIteration`.

---

Let me know if you want this extended with generator syntax, bidirectional iteration, or visual diagrams for your vault.