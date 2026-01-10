## 📘 Study Note: 3D Coordinates with List Comprehension

### 🧾 Problem Statement
Generate valid coordinate triplets in a 3D space excluding a specific constraint surface defined by i + j + k != n.

### ✅ Code Explanation
```python
if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    result = [[i, j, k] for i in range(x + 1)
                         for j in range(y + 1)
                         for k in range(z + 1)
                         if i + j + k != n]
    print(result)
```

### 🧠 Concepts Applied
- **List comprehensions**: A concise way to create lists in Python
- **Cartesian product simulation**: Generating all possible combinations of i, j, k within given ranges
- **Conditional filtering**: Using `if` condition to filter out combinations that don't meet criteria
- **Input-driven grid traversal**: Using input values to define the search space

### 💡 Insight for Algorithmic Thinking
The condition `i + j + k != n` acts as a dynamic filter over the generated 3D space, allowing exploration of how constraints shape output in combinatorics. Understanding how to apply constraints during generation is critical in recursion, backtracking, and subset formation tasks.

### 🔗 Related Problems
- Similar pattern used in generating permutations and combinations
- Useful in constraint satisfaction problems