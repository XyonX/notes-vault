Got it ✅ I’ll make you clean **Obsidian notes** where each problem has:

- **C++-style (loop/logic)** solution you wrote/know.
    
- **Pythonic-style (short/built-in)** solution.
    

That way you’ll have a nice **side-by-side comparison** for revision.

---

# 🐍 Python Lists – C++ style vs Pythonic style

---

## 01. Reverse a List

```python
nums = [1, 2, 3, 4, 5]
```

**C++ style (logic):**

```python
# Using slicing in reverse order
print(nums[::-1])
```

**Pythonic style:**

```python
# In-place reverse
nums.reverse()
print(nums)

# OR using reversed()
print(list(reversed(nums)))
```

---

## 02. Find Minimum and Maximum

```python
nums = [12, 4, 67, 23, 89, 1]
```

**C++ style (manual loop):**

```python
min_val = 9999999
max_val = -9999999
for i in nums:
    if i > max_val:
        max_val = i
    if i < min_val:
        min_val = i
print(min_val, max_val)
```

**Pythonic style:**

```python
print(min(nums), max(nums))
```

---

## 03. Remove Duplicates (Keep Order)

```python
nums = [1, 2, 2, 3, 4, 4, 5]
```

**C++ style (two-pointer technique):**

```python
l = 0
for r in range(1, len(nums)):
    if nums[r] != nums[l]:
        l += 1
        nums[l] = nums[r]
nums[:] = nums[:l+1]
print(nums)   # [1, 2, 3, 4, 5]
```

**Pythonic style:**

```python
# Method 1: using dict.fromkeys (keeps order)
print(list(dict.fromkeys(nums)))

# Method 2: using set (order not guaranteed)
print(list(set(nums)))

# Method 3: simple loop
seen = []
for x in nums:
    if x not in seen:
        seen.append(x)
print(seen)
```

---

💡 **Key takeaway:**

- C++ style = good for **understanding algorithms & complexity**.
    
- Pythonic style = great for **short, clean, real-world coding**.
    

---

Do you want me to continue adding the **Level 2 list problems (rotation, evens, flatten)** in the same **C++ vs Pythonic** note format?