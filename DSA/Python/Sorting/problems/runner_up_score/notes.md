## 📘 Study Note: Finding the Runner-Up Score in Python

### 🧾 Problem Statement
You are given a list of scores from a competition. The task is to determine the **second-highest** score (also called the runner-up score) from that list.

### ✅ Final Code
```python
if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    scores = set(arr)            # Remove duplicates
    list1 = list(scores)         # Convert to list
    list1.sort()                 # Sort ascending
    print(list1[-2])             # Second highest = second last element
```

### 🧠 Concepts Applied
- **`map()` and `input().split()`**: Converts space-separated string input into integers.
- **`set()`**: Automatically removes duplicate scores to ensure accuracy in ranking.
- **`sort()`**: Arranges scores in ascending order.
- **Indexing with `[-2]`**: Fetches second-highest score from sorted list.

### 💡 Insight for Algorithmic Thinking
This technique sidesteps manual comparison or iteration by using Python's built-in tools, offering clarity and efficiency. You're essentially transforming the data into a form where direct access to the runner-up becomes trivial.

### 🔗 Related Problems
- Finding the kth largest element
- Finding top k elements
- Removing duplicates from a list