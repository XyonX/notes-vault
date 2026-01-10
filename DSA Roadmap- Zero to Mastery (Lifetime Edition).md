# 🚀 Ultimate DSA Roadmap:  Zero to Mastery (Lifetime Edition)

Since you already have foundational experience, this roadmap will help you **reorganize, revise, and master** DSA systematically. You can bookmark this and follow it forever! 

---

## 📋 **Roadmap Overview**

| Phase | Focus | Duration | Difficulty |
|-------|-------|----------|------------|
| Phase 1 | Foundations & Math | Week 1-2 | ⭐ Easy |
| Phase 2 | Arrays & Strings | Week 3-4 | ⭐⭐ Easy-Medium |
| Phase 3 | Hashing & Two Pointers | Week 5-6 | ⭐⭐ Medium |
| Phase 4 | Sliding Window & Prefix | Week 7-8 | ⭐⭐ Medium |
| Phase 5 | Sorting & Searching | Week 9-10 | ⭐⭐ Medium |
| Phase 6 | Recursion & Backtracking | Week 11-13 | ⭐⭐⭐ Medium-Hard |
| Phase 7 | Linked Lists | Week 14-15 | ⭐⭐ Medium |
| Phase 8 | Stacks & Queues | Week 16-18 | ⭐⭐⭐ Medium |
| Phase 9 | Trees (Binary, BST) | Week 19-22 | ⭐⭐⭐ Medium-Hard |
| Phase 10 | Heaps & Priority Queues | Week 23-24 | ⭐⭐⭐ Medium |
| Phase 11 | Graphs (BFS, DFS) | Week 25-28 | ⭐⭐⭐⭐ Hard |
| Phase 12 | Advanced Graphs | Week 29-32 | ⭐⭐⭐⭐ Hard |
| Phase 13 | Dynamic Programming | Week 33-40 | ⭐⭐⭐⭐⭐ Hard |
| Phase 14 | Greedy Algorithms | Week 41-42 | ⭐⭐⭐ Medium-Hard |
| Phase 15 | Tries & Advanced Strings | Week 43-44 | ⭐⭐⭐⭐ Hard |
| Phase 16 | Segment Trees & Fenwick | Week 45-46 | ⭐⭐⭐⭐⭐ Advanced |
| Phase 17 | Bit Manipulation | Week 47-48 | ⭐⭐⭐ Medium |
| Phase 18 | Math & Number Theory | Week 49-50 | ⭐⭐⭐⭐ Hard |
| Phase 19 | Mixed Practice & Contests | Week 51-52+ | All Levels |

---

## 📖 **PHASE 1: Foundations & Basic Math** (Week 1-2)

### 📝 Topics
```
□ Time & Space Complexity (Big O)
□ Basic Math Operations
□ Number Properties
□ Pattern Problems (for logic building)
```

### 🎯 Problems to Solve

#### Complexity Analysis
- [x] Understand O(1), O(n), O(n²), O(log n), O(n log n)
- [x] Analyze complexity of nested loops
- [x] Space complexity basics

#### Basic Math
- [ ] Count digits in a number
- [ ] Reverse a number
- [ ] Check Palindrome number
- [ ] Armstrong Number
- [ ] GCD/HCF (Euclidean Algorithm)
- [ ] LCM
- [ ] Check Prime
- [ ] Prime Factorization
- [ ] Sieve of Eratosthenes
- [ ] Power of a number (fast exponentiation)
- [ ] Factorial
- [ ] Fibonacci (iterative)
- [ ] Sum of divisors
- [ ] Check Perfect Number

#### Pattern Problems (Logic Building)
- [ ] Right-angled triangle pattern
- [ ] Inverted triangle
- [ ] Pyramid pattern
- [ ] Diamond pattern
- [ ] Number patterns
- [ ] Character patterns

### 📓 Short Notes Template
```markdown
## Phase 1 Notes

### Time Complexity Cheatsheet
- O(1): Constant - direct access
- O(log n): Binary search, divide & conquer
- O(n): Linear traversal
- O(n log n): Efficient sorting (merge, quick)
- O(n²): Nested loops, bubble sort
- O(2^n): Recursion with 2 branches

### Math Formulas
- GCD:  gcd(a,b) = gcd(b, a%b), base:  gcd(a,0) = a
- LCM: (a * b) / gcd(a,b)
- Prime check: iterate till √n
- Sieve: mark multiples starting from 2

### Patterns to Remember
- [Your pattern notes here]
```

---

## 📖 **PHASE 2: Arrays & Strings Basics** (Week 3-4)

### 📝 Topics
```
□ Array traversal & manipulation
□ Basic string operations
□ In-place modifications
□ Frequency counting
```

### 🎯 Problems to Solve

#### Arrays - Easy
- [ ] Find largest/smallest element
- [ ] Find second largest
- [ ] Check if array is sorted
- [ ] Remove duplicates from sorted array
- [ ] Rotate array by K positions (left/right)
- [ ] Move zeros to end
- [ ] Union & Intersection of arrays
- [ ] Find missing number (1 to N)
- [ ] Maximum consecutive ones
- [ ] Single number (XOR)

#### Arrays - Medium Basics
- [ ] Two Sum (brute force first, then optimal)
- [ ] Sort 0s, 1s, 2s (Dutch National Flag)
- [ ] Majority Element (Moore's Voting)
- [ ] Kadane's Algorithm (Max Subarray Sum)
- [ ] Stock Buy & Sell (one transaction)
- [ ] Rearrange by sign
- [ ] Next Permutation
- [ ] Leaders in array
- [ ] Longest consecutive sequence

#### Strings - Easy
- [ ] Reverse a string
- [ ] Check palindrome
- [ ] Check anagram
- [ ] Remove vowels
- [ ] Count words in string
- [ ] First non-repeating character
- [ ] Valid parentheses (basic)

### 📓 Short Notes Template
```markdown
## Phase 2 Notes

### Array Patterns
- Kadane's:  maxSum = max(arr[i], maxSum + arr[i])
- Dutch Flag: 3 pointers (low, mid, high)
- Moore's Voting: count-based majority finding
- Rotation: reverse technique (reverse parts, reverse all)

### String Patterns
- Anagram:  sort both OR frequency count
- Palindrome: two pointers from ends

### Key Tricks
- Missing number: XOR all with 1.. n OR sum formula
- Single number: XOR all elements
```

---

## 📖 **PHASE 3: Hashing & Two Pointers** (Week 5-6)

### 📝 Topics
```
□ HashMap/HashSet usage
□ Frequency maps
□ Two pointer technique
□ Opposite direction pointers
□ Same direction pointers
```

### 🎯 Problems to Solve

#### Hashing
- [ ] Two Sum (HashMap approach)
- [ ] Count frequency of elements
- [ ] Find duplicates
- [ ] First unique character
- [ ] Group Anagrams
- [ ] Longest substring without repeating chars
- [ ] Subarray sum equals K
- [ ] Count subarrays with given XOR
- [ ] Longest consecutive sequence (optimal)
- [ ] 4Sum (hashing approach)

#### Two Pointers
- [ ] Two Sum II (sorted array)
- [ ] 3Sum
- [ ] 3Sum Closest
- [ ] 4Sum
- [ ] Container with most water
- [ ] Trapping rainwater
- [ ] Remove duplicates (two pointers)
- [ ] Merge sorted arrays
- [ ] Sort colors
- [ ] Valid palindrome (with special chars)
- [ ] Reverse words in string

### 📓 Short Notes Template
```markdown
## Phase 3 Notes

### Hashing Patterns
- Sum problems: store complement in map
- Subarray sum K: prefix sum + map (prefix - K exists?)
- Frequency:  map[element]++
- Anagram grouping: sorted string as key

### Two Pointer Patterns
1. Opposite ends: start=0, end=n-1 (sorted arrays, palindrome)
2. Same direction: slow/fast (remove duplicates, cycle)
3. Two arrays: one pointer each (merge)

### Templates
```python
# Subarray sum = K
prefix = 0
map = {0: 1}
for num in arr:
    prefix += num
    if prefix - k in map: 
        count += map[prefix - k]
    map[prefix] = map.get(prefix, 0) + 1
```
```

---

## 📖 **PHASE 4: Sliding Window & Prefix Sum** (Week 7-8)

### 📝 Topics
```
□ Fixed size window
□ Variable size window
□ Prefix sum technique
□ Difference array
```

### 🎯 Problems to Solve

#### Fixed Sliding Window
- [ ] Maximum sum of subarray of size K
- [ ] First negative in every window of size K
- [ ] Count anagram occurrences
- [ ] Max of all subarrays of size K (using deque)
- [ ] Average of subarrays of size K

#### Variable Sliding Window
- [ ] Longest substring with K unique characters
- [ ] Longest substring without repeating characters
- [ ] Minimum window substring
- [ ] Longest repeating character replacement
- [ ] Fruits into baskets (at most 2 types)
- [ ] Subarray product less than K
- [ ] Minimum size subarray sum ≥ target
- [ ] Permutation in string
- [ ] Find all anagrams in string

#### Prefix Sum
- [ ] Range sum query (immutable)
- [ ] Subarray sum equals K
- [ ] Contiguous array (0s and 1s)
- [ ] Product of array except self
- [ ] 2D prefix sum basics

### 📓 Short Notes Template
```markdown
## Phase 4 Notes

### Sliding Window Template
```python
# Variable Window
left = 0
for right in range(n):
    # Add arr[right] to window
    
    while window_invalid():
        # Remove arr[left] from window
        left += 1
    
    # Update answer
```

### Fixed vs Variable
- Fixed:  window size constant, slide one step
- Variable:  expand right, shrink left based on condition

### Prefix Sum
- prefix[i] = sum of arr[0..i-1]
- Sum(l,r) = prefix[r+1] - prefix[l]
- Build:  O(n), Query: O(1)

### Common Patterns
- "At most K" → Variable window, shrink when exceeds K
- "Exactly K" → AtMost(K) - AtMost(K-1)
```

---

## 📖 **PHASE 5: Sorting & Searching** (Week 9-10)

### 📝 Topics
```
□ All sorting algorithms
□ Binary search variations
□ Search in rotated arrays
□ Search answer pattern
```

### 🎯 Problems to Solve

#### Sorting Algorithms (Implement All)
- [ ] Bubble Sort
- [ ] Selection Sort
- [ ] Insertion Sort
- [ ] Merge Sort
- [ ] Quick Sort
- [ ] Counting Sort
- [ ] Radix Sort (understand concept)
- [ ] Heap Sort (after heaps phase)

#### Binary Search - Basics
- [ ] Binary search in sorted array
- [ ] Lower Bound
- [ ] Upper Bound
- [ ] First and last occurrence
- [ ] Count occurrences
- [ ] Search insert position
- [ ] Floor and Ceil in sorted array

#### Binary Search - Rotated Arrays
- [ ] Search in rotated sorted array
- [ ] Search in rotated with duplicates
- [ ] Find minimum in rotated array
- [ ] Find rotation count
- [ ] Single element in sorted array

#### Binary Search on Answer
- [ ] Square root of number
- [ ] Nth root of number
- [ ] Koko eating bananas
- [ ] Minimum days to make bouquets
- [ ] Capacity to ship packages
- [ ] Aggressive cows / Magnetic balls
- [ ] Split array largest sum
- [ ] Painter's partition
- [ ] Book allocation
- [ ] Median of two sorted arrays

### 📓 Short Notes Template
```markdown
## Phase 5 Notes

### Sorting Complexities
| Algorithm | Time (Avg) | Time (Worst) | Space | Stable |
|-----------|------------|--------------|-------|--------|
| Bubble    | O(n²)      | O(n²)        | O(1)  | Yes    |
| Selection | O(n²)      | O(n²)        | O(1)  | No     |
| Insertion | O(n²)      | O(n²)        | O(1)  | Yes    |
| Merge     | O(n log n) | O(n log n)   | O(n)  | Yes    |
| Quick     | O(n log n) | O(n²)        | O(log n) | No  |
| Heap      | O(n log n) | O(n log n)   | O(1)  | No     |

### Binary Search Templates
```python
# Standard
while low <= high:
    mid = (low + high) // 2
    if arr[mid] == target:  return mid
    elif arr[mid] < target: low = mid + 1
    else: high = mid - 1

# Lower Bound (first >= target)
while low <= high:
    mid = (low + high) // 2
    if arr[mid] >= target: 
        ans = mid
        high = mid - 1
    else: 
        low = mid + 1
```

### Binary Search on Answer
- Identify:  "minimum maximum" or "maximum minimum"
- Define search space [min_possible, max_possible]
- Check if mid is valid answer
- Narrow based on validity
```

---

## 📖 **PHASE 6: Recursion & Backtracking** (Week 11-13)

### 📝 Topics
```
□ Recursion basics & thinking
□ Subsequences pattern
□ Backtracking framework
□ Permutations & Combinations
```

### 🎯 Problems to Solve

#### Recursion Basics
- [ ] Print 1 to N, N to 1
- [ ] Sum of N numbers
- [ ] Factorial
- [ ] Fibonacci
- [ ] Reverse array
- [ ] Check palindrome
- [ ] Power function

#### Subsequences Pattern
- [ ] Print all subsequences
- [ ] Subsequences with sum K
- [ ] Count subsequences with sum K
- [ ] Subset Sum I (exists or not)
- [ ] Subset Sum II (with duplicates)
- [ ] Combination Sum I (unlimited use)
- [ ] Combination Sum II (use once)
- [ ] Combination Sum III
- [ ] Letter combinations of phone number

#### Backtracking
- [ ] Generate all subsets/powerset
- [ ] Generate all permutations
- [ ] Permutations II (with duplicates)
- [ ] N-Queens
- [ ] Sudoku Solver
- [ ] Rat in a Maze
- [ ] Word Search
- [ ] Palindrome Partitioning
- [ ] M-Coloring Problem
- [ ] Generate Parentheses

### 📓 Short Notes Template
```markdown
## Phase 6 Notes

### Recursion Template
```python
def solve(index, current_state):
    # Base case
    if index == n:
        process(current_state)
        return
    
    # Recursive cases
    solve(index + 1, current_state)  # Don't take
    solve(index + 1, current_state + arr[index])  # Take
```

### Backtracking Template
```python
def backtrack(path, choices):
    if is_solution(path):
        result.append(path. copy())
        return
    
    for choice in choices: 
        if is_valid(choice):
            path.append(choice)  # Make choice
            backtrack(path, remaining_choices)
            path.pop()  # Undo choice
```

### Key Insights
- Subsequence: Pick/Not pick pattern
- Permutation:  Swap-based or used[] array
- Combination:  Start from index to avoid duplicates
- Pruning: Skip invalid paths early
```

---

## 📖 **PHASE 7: Linked Lists** (Week 14-15)

### 📝 Topics
```
□ Singly Linked List
□ Doubly Linked List
□ Fast & Slow pointers
□ Reversal techniques
```

### 🎯 Problems to Solve

#### Basics
- [ ] Implement Singly Linked List
- [ ] Implement Doubly Linked List
- [ ] Traverse and print
- [ ] Insert at head/tail/position
- [ ] Delete from head/tail/position
- [ ] Search in linked list
- [ ] Length of linked list

#### Classic Problems
- [ ] Reverse linked list (iterative)
- [ ] Reverse linked list (recursive)
- [ ] Middle of linked list
- [ ] Detect cycle
- [ ] Find cycle starting point
- [ ] Length of cycle
- [ ] Palindrome linked list
- [ ] Merge two sorted lists
- [ ] Remove Nth node from end
- [ ] Add two numbers
- [ ] Intersection of two lists

#### Medium-Hard
- [ ] Reverse in groups of K
- [ ] Rotate list by K
- [ ] Flatten a multilevel list
- [ ] Clone list with random pointer
- [ ] Merge K sorted lists
- [ ] Sort linked list (Merge Sort)
- [ ] Remove duplicates
- [ ] Odd-Even linked list
- [ ] Reorder list

### 📓 Short Notes Template
```markdown
## Phase 7 Notes

### Linked List Patterns

#### Reverse Template
```python
prev, curr = None, head
while curr: 
    next_node = curr.next
    curr.next = prev
    prev = curr
    curr = next_node
return prev
```

#### Fast-Slow Pointer
```python
slow = fast = head
while fast and fast.next:
    slow = slow.next
    fast = fast.next. next
# slow is at middle (or start of second half)
```

### Common Patterns
- Middle:  slow-fast pointer
- Cycle detection: Floyd's algorithm
- Intersection: length difference OR hash
- Reversal: 3 pointer technique
- Nth from end: Two pointer with N gap
```

---

## 📖 **PHASE 8: Stacks & Queues** (Week 16-18)

### 📝 Topics
```
□ Stack fundamentals
□ Queue fundamentals
□ Monotonic stack/queue
□ Next Greater Element pattern
```

### 🎯 Problems to Solve

#### Stack Basics
- [ ] Implement stack using array
- [ ] Implement stack using linked list
- [ ] Implement stack using queue
- [ ] Valid parentheses
- [ ] Min Stack
- [ ] Evaluate postfix expression
- [ ] Infix to postfix

#### Queue Basics
- [ ] Implement queue using array
- [ ] Implement queue using linked list
- [ ] Implement queue using stacks
- [ ] Implement circular queue
- [ ] Design deque

#### Monotonic Stack (⭐Important Pattern)
- [ ] Next Greater Element I
- [ ] Next Greater Element II (circular)
- [ ] Next Smaller Element
- [ ] Previous Greater Element
- [ ] Previous Smaller Element
- [ ] Largest Rectangle in Histogram
- [ ] Maximal Rectangle
- [ ] Trapping Rain Water (stack approach)
- [ ] Remove K digits
- [ ] Sum of subarray minimums
- [ ] Sum of subarray ranges
- [ ] Asteroid collision
- [ ] Daily temperatures
- [ ] Stock span problem
- [ ] Online stock span

#### Other Stack Problems
- [ ] Simplify path
- [ ] Decode string
- [ ] Basic calculator I, II, III
- [ ] Remove duplicate letters
- [ ] 132 Pattern

### 📓 Short Notes Template
```markdown
## Phase 8 Notes

### Monotonic Stack Template
```python
# Next Greater Element
stack = []
result = [-1] * n
for i in range(n-1, -1, -1):
    while stack and stack[-1] <= arr[i]:
        stack.pop()
    if stack:
        result[i] = stack[-1]
    stack.append(arr[i])
```

### Patterns
| Problem | Stack Type | Direction |
|---------|-----------|-----------|
| Next Greater | Decreasing | Right to Left |
| Next Smaller | Increasing | Right to Left |
| Prev Greater | Decreasing | Left to Right |
| Prev Smaller | Increasing | Left to Right |

### Histogram Pattern
- For each bar:  find left smaller, right smaller
- Width = right - left - 1
- Area = height * width
```

---

## 📖 **PHASE 9: Trees** (Week 19-22)

### 📝 Topics
```
□ Binary Tree traversals
□ Binary Tree properties
□ Binary Search Tree
□ Tree construction
```

### 🎯 Problems to Solve

#### Traversals (Must Master)
- [ ] Inorder (recursive + iterative)
- [ ] Preorder (recursive + iterative)
- [ ] Postorder (recursive + iterative)
- [ ] Level order traversal
- [ ] Zigzag level order
- [ ] Vertical order traversal
- [ ] Boundary traversal
- [ ] Morris traversal (inorder)

#### Binary Tree Properties
- [ ] Height of tree
- [ ] Diameter of tree
- [ ] Maximum path sum
- [ ] Check balanced tree
- [ ] Check identical trees
- [ ] Check symmetric tree
- [ ] Lowest Common Ancestor
- [ ] Maximum width of tree
- [ ] Count nodes in complete binary tree

#### Binary Tree Views
- [ ] Left view
- [ ] Right view
- [ ] Top view
- [ ] Bottom view
- [ ] Root to node path
- [ ] All root to leaf paths

#### Construction & Conversion
- [ ] Build tree from inorder + preorder
- [ ] Build tree from inorder + postorder
- [ ] Serialize and deserialize
- [ ] Flatten tree to linked list
- [ ] Convert to mirror tree

#### Binary Search Tree
- [ ] Search in BST
- [ ] Insert in BST
- [ ] Delete from BST
- [ ] Validate BST
- [ ] LCA in BST
- [ ] Kth smallest in BST
- [ ] Floor and Ceil in BST
- [ ] Two sum in BST
- [ ] Recover BST (two swapped)
- [ ] Inorder successor/predecessor
- [ ] Construct BST from preorder
- [ ] Merge two BSTs

### 📓 Short Notes Template
```markdown
## Phase 9 Notes

### Traversal Patterns
```
Inorder:    Left → Root → Right  (BST gives sorted)
Preorder:   Root → Left → Right  (used to copy tree)
Postorder:  Left → Right → Root  (used to delete tree)
```

### DFS Template
```python
def dfs(node):
    if not node:
        return base_value
    
    left = dfs(node. left)
    right = dfs(node.right)
    
    # Process current node
    return result
```

### Key Patterns
- Height: 1 + max(left_height, right_height)
- Diameter: max of (left_h + right_h) at each node
- LCA:  if both sides return node, current is LCA
- Path sum: carry sum parameter down

### BST Property
- Left subtree < Node < Right subtree
- Inorder gives sorted sequence
```

---

## 📖 **PHASE 10: Heaps & Priority Queues** (Week 23-24)

### 📝 Topics
```
□ Min/Max Heap implementation
□ Priority Queue usage
□ Top K pattern
□ Two heap pattern
```

### 🎯 Problems to Solve

#### Implementation
- [ ] Implement Min Heap
- [ ] Implement Max Heap
- [ ] Heap Sort
- [ ] Convert array to heap (heapify)

#### Top K Pattern
- [ ] Kth largest element
- [ ] Kth smallest element
- [ ] Top K frequent elements
- [ ] K closest points to origin
- [ ] Sort characters by frequency
- [ ] K closest numbers
- [ ] Top K frequent words

#### Two Heaps Pattern
- [ ] Find median from data stream
- [ ] Sliding window median
- [ ] IPO problem

#### Merge Pattern
- [ ] Merge K sorted lists
- [ ] Merge K sorted arrays
- [ ] Smallest range covering K lists
- [ ] Find K pairs with smallest sums

#### Other Heap Problems
- [ ] Task scheduler
- [ ] Reorganize string
- [ ] Furthest building you can reach
- [ ] Minimum cost to connect sticks
- [ ] Maximum score from removing stones

### 📓 Short Notes Template
```markdown
## Phase 10 Notes

### Heap Cheatsheet
- Min Heap: parent <= children (root is min)
- Max Heap: parent >= children (root is max)
- Insert: O(log n), Extract: O(log n), Peek: O(1)
- Heapify array: O(n)

### When to Use Which
- Kth largest → Min heap of size K
- Kth smallest → Max heap of size K
- Top K largest → Min heap of size K
- Top K smallest → Max heap of size K

### Two Heaps Pattern
```python
# Median stream
max_heap = []  # left half (negate values)
min_heap = []  # right half

# Balance:  len(max) == len(min) or len(max) == len(min) + 1
# Median: max_heap[0] or (max_heap[0] + min_heap[0]) / 2
```

### Python heapq
- heapq.heappush(heap, item)
- heapq.heappop(heap)
- heapq.heapify(list)
- For max heap: negate values
```

---

## 📖 **PHASE 11: Graphs - Basics** (Week 25-28)

### 📝 Topics
```
□ Graph representation
□ BFS traversal
□ DFS traversal
□ Cycle detection
□ Topological sort
```

### 🎯 Problems to Solve

#### Representation & Basics
- [ ] Adjacency Matrix implementation
- [ ] Adjacency List implementation
- [ ] BFS traversal
- [ ] DFS traversal
- [ ] Connected components
- [ ] Number of islands
- [ ] Flood fill

#### BFS Problems
- [ ] Rotting oranges
- [ ] 01 Matrix (nearest 0)
- [ ] Surrounded regions
- [ ] Number of enclaves
- [ ] Word ladder
- [ ] Shortest path in binary matrix
- [ ] Shortest bridge
- [ ] Open the lock
- [ ] Minimum genetic mutation

#### DFS Problems
- [ ] Clone graph
- [ ] Number of provinces
- [ ] Keys and rooms
- [ ] Pacific Atlantic water flow
- [ ] All paths from source to target
- [ ] Reconstruct itinerary

#### Cycle Detection
- [ ] Detect cycle in undirected graph (BFS)
- [ ] Detect cycle in undirected graph (DFS)
- [ ] Detect cycle in directed graph (DFS)
- [ ] Detect cycle in directed graph (Kahn's)

#### Topological Sort
- [ ] Topological sort (DFS)
- [ ] Topological sort (Kahn's BFS)
- [ ] Course Schedule I
- [ ] Course Schedule II
- [ ] Alien Dictionary
- [ ] Find eventual safe states

### 📓 Short Notes Template
```markdown
## Phase 11 Notes

### Graph Representations
```python
# Adjacency List (most common)
graph = defaultdict(list)
graph[u].append(v)

# Adjacency Matrix
matrix = [[0] * n for _ in range(n)]
matrix[u][v] = 1
```

### BFS Template
```python
from collections import deque
def bfs(start):
    queue = deque([start])
    visited = {start}
    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if neighbor not in visited: 
                visited.add(neighbor)
                queue.append(neighbor)
```

### DFS Template
```python
def dfs(node, visited):
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited: 
            dfs(neighbor, visited)
```

### Cycle Detection
- Undirected: parent tracking (node visited & not parent)
- Directed: recursion stack (visiting vs visited)

### Topological Sort
- Only for DAG (Directed Acyclic Graph)
- DFS:  add to result after visiting all neighbors
- Kahn's: process nodes with 0 indegree
```

---

## 📖 **PHASE 12: Graphs - Advanced** (Week 29-32)

### 📝 Topics
```
□ Shortest path algorithms
□ Minimum Spanning Tree
□ Disjoint Set Union
□ Bipartite & Coloring
```

### 🎯 Problems to Solve

#### Shortest Path
- [ ] Dijkstra's algorithm
- [ ] Bellman-Ford algorithm
- [ ] Floyd-Warshall algorithm
- [ ] Shortest path in DAG
- [ ] Network delay time
- [ ] Path with minimum effort
- [ ] Cheapest flights within K stops
- [ ] Number of ways to reach destination
- [ ] Minimum cost to make valid path

#### Minimum Spanning Tree
- [ ] Prim's algorithm
- [ ] Kruskal's algorithm
- [ ] Min cost to connect all points
- [ ] Connecting cities with minimum cost

#### Disjoint Set Union (Union-Find)
- [ ] Implement DSU with rank & path compression
- [ ] Number of connected components
- [ ] Redundant connection
- [ ] Accounts merge
- [ ] Most stones removed
- [ ] Making a large island
- [ ] Number of operations to make network connected
- [ ] Swim in rising water

#### Bipartite & Special Graphs
- [ ] Check bipartite (BFS/DFS)
- [ ] Possible bipartition
- [ ] Is Graph tree
- [ ] Strongly connected components (Kosaraju's)
- [ ] Bridges in graph (Tarjan's)
- [ ] Articulation points

### 📓 Short Notes Template
```markdown
## Phase 12 Notes

### Dijkstra's Template
```python
import heapq
def dijkstra(graph, start):
    dist = {start: 0}
    heap = [(0, start)]
    while heap:
        d, u = heapq. heappop(heap)
        if d > dist.get(u, float('inf')):
            continue
        for v, w in graph[u]:
            if d + w < dist. get(v, float('inf')):
                dist[v] = d + w
                heapq. heappush(heap, (dist[v], v))
    return dist
```

### Union-Find Template
```python
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:  return False
        if self.rank[px] < self.rank[py]:
            px, py = py, px
        self. parent[py] = px
        if self.rank[px] == self.rank[py]:
            self.rank[px] += 1
        return True
```

### Algorithm Comparison
| Algorithm | Graph Type | Negative Edges | Time |
|-----------|-----------|----------------|------|
| Dijkstra | Any | No | O(E log V) |
| Bellman-Ford | Any | Yes | O(VE) |
| Floyd-Warshall | Any | Yes | O(V³) |
| Prim's | Undirected | Any | O(E log V) |
| Kruskal's | Undirected | Any | O(E log E) |
```

---

## 📖 **PHASE 13: Dynamic Programming** (Week 33-40)

### 📝 Topics
```
□ 1D DP
□ 2D DP
□ DP on strings
□ DP on subsequences
□ Partition DP
□ DP on stocks
□ DP on grids
□ State machine DP
```

### 🎯 Problems to Solve

#### 1D DP Basics
- [ ] Climbing stairs
- [ ] Frog jump
- [ ] House robber
- [ ] House robber II (circular)
- [ ] Maximum sum non-adjacent
- [ ] Decode ways
- [ ] Perfect squares
- [ ] Coin change (minimum coins)
- [ ] Coin change 2 (count ways)
- [ ] Minimum cost for tickets

#### 2D/Grid DP
- [ ] Unique paths
- [ ] Unique paths II (with obstacles)
- [ ] Minimum path sum
- [ ] Triangle minimum path
- [ ] Minimum falling path sum
- [ ] Cherry pickup
- [ ] Dungeon game

#### Subsequence DP
- [ ] Longest Increasing Subsequence (LIS)
- [ ] Print LIS
- [ ] Number of LIS
- [ ] Longest divisible subset
- [ ] Longest string chain
- [ ] Longest Bitonic subsequence

#### String DP
- [ ] Longest Common Subsequence
- [ ] Print LCS
- [ ] Longest Common Substring
- [ ] Shortest common supersequence
- [ ] Edit distance
- [ ] Minimum insertions for palindrome
- [ ] Minimum deletions for palindrome
- [ ] Longest palindromic subsequence
- [ ] Distinct subsequences
- [ ] Wildcard matching
- [ ] Regular expression matching

#### Partition DP
- [ ] Matrix chain multiplication
- [ ] Minimum cost to cut stick
- [ ] Burst balloons
- [ ] Palindrome partitioning II
- [ ] Boolean parenthesization
- [ ] Partition array for maximum sum

#### Stock DP Series
- [ ] Best time to buy and sell I (one transaction)
- [ ] Best time to buy and sell II (unlimited)
- [ ] Best time to buy and sell III (at most 2)
- [ ] Best time to buy and sell IV (at most K)
- [ ] With cooldown
- [ ] With transaction fee

#### Knapsack Pattern
- [ ] 0/1 Knapsack
- [ ] Subset sum
- [ ] Partition equal subset sum
- [ ] Count subsets with given difference
- [ ] Target sum (+ and -)
- [ ] Unbounded knapsack
- [ ] Rod cutting
- [ ] Coin change variations

#### Advanced DP
- [ ] Egg dropping
- [ ] Word break
- [ ] Word break II
- [ ] Interleaving string
- [ ] Maximal square
- [ ] Maximal rectangle

### 📓 Short Notes Template
```markdown
## Phase 13 Notes

### DP Approach
1. Identify subproblems
2. Find recurrence relation
3. Identify base cases
4. Decide:  top-down (memoization) or bottom-up (tabulation)
5. Optimize space if possible

### Common Patterns

#### Knapsack Template
```python
# 0/1 Knapsack
dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i]] + val[i])

# Unbounded
dp[i][w] = max(dp[i-1][w], dp[i][w-wt[i]] + val[i])
```

#### LCS Template
```python
if s1[i-1] == s2[j-1]: 
    dp[i][j] = 1 + dp[i-1][j-1]
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

#### LIS (O(n log n))
```python
from bisect import bisect_left
tails = []
for num in arr:
    pos = bisect_left(tails, num)
    if pos == len(tails):
        tails. append(num)
    else:
        tails[pos] = num
return len(tails)
```

### Space Optimization
- 2D → 1D: when dp[i] depends only on dp[i-1]
- Use prev and curr arrays
```

---

## 📖 **PHASE 14: Greedy Algorithms** (Week 41-42)

### 📝 Topics
```
□ Greedy intuition
□ Activity selection
□ Interval problems
□ Job scheduling
```

### 🎯 Problems to Solve

#### Classic Greedy
- [ ] Fractional knapsack
- [ ] Activity selection
- [ ] N meetings in one room
- [ ] Minimum platforms
- [ ] Job sequencing problem
- [ ] Huffman encoding

#### Interval Problems
- [ ] Merge intervals
- [ ] Insert interval
- [ ] Non-overlapping intervals (min removals)
- [ ] Meeting rooms I, II
- [ ] Minimum arrows to burst balloons

#### Other Greedy
- [ ] Jump game I
- [ ] Jump game II
- [ ] Gas station
- [ ] Candy distribution
- [ ] Lemonade change
- [ ] Queue reconstruction by height
- [ ] Assign cookies
- [ ] Partition labels
- [ ] Task scheduler
- [ ] Minimum number of coins

### 📓 Short Notes Template
```markdown
## Phase 14 Notes

### Greedy Approach
1. Make locally optimal choice
2. Hope it leads to global optimum
3. Prove correctness (exchange argument)

### Interval Pattern
```python
# Sort by end time for activity selection
intervals.sort(key=lambda x: x[1])

# Sort by start time for merge
intervals.sort(key=lambda x:  x[0])
```

### When Greedy Works
- Optimal substructure
- Greedy choice property
- Usually involves sorting

### Common Mistakes
- Not all problems have greedy solutions
- Verify with examples before coding
- If greedy fails, try DP
```

---

## 📖 **PHASE 15: Tries & Advanced Strings** (Week 43-44)

### 📝 Topics
```
□ Trie implementation
□ Trie applications
□ String algorithms (KMP, Rabin-Karp)
```

### 🎯 Problems to Solve

#### Trie Implementation
- [ ] Implement Trie (insert, search, startsWith)
- [ ] Implement Trie with count (prefixes, words)

#### Trie Problems
- [ ] Word Search II (Trie + Backtracking)
- [ ] Design Add and Search Words
- [ ] Replace words
- [ ] Longest word in dictionary
- [ ] Maximum XOR of two numbers
- [ ] Maximum XOR with element from array
- [ ] Count distinct substrings

#### String Algorithms
- [ ] KMP pattern matching
- [ ] Rabin-Karp pattern matching
- [ ] Z-algorithm
- [ ] Longest Happy Prefix
- [ ] Repeated string match
- [ ] Shortest palindrome (KMP)

### 📓 Short Notes Template
```markdown
## Phase 15 Notes

### Trie Template
```python
class TrieNode: 
    def __init__(self):
        self.children = {}
        self.is_end = False

class Trie: 
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self. root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_end = True
    
    def search(self, word):
        node = self.root
        for c in word:
            if c not in node.children:
                return False
            node = node.children[c]
        return node. is_end
```

### KMP Algorithm
```python
def compute_lps(pattern):
    lps = [0] * len(pattern)
    length, i = 0, 1
    while i < len(pattern):
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        elif length: 
            length = lps[length - 1]
        else:
            lps[i] = 0
            i += 1
    return lps
```

### Use Cases
- Trie:  prefix search, autocomplete, spell checker
- KMP: exact pattern matching O(n+m)
- Rabin-Karp:  multiple pattern matching
```

---

## 📖 **PHASE 16: Segment Trees & Fenwick Trees** (Week 45-46)

### 📝 Topics
```
□ Segment Tree (build, query, update)
□ Lazy Propagation
□ Fenwick Tree (BIT)
```

### 🎯 Problems to Solve

#### Segment Tree
- [ ] Build segment tree
- [ ] Range sum query (mutable)
- [ ] Range min/max query
- [ ] Point update
- [ ] Range update (lazy propagation)
- [ ] Count of smaller numbers after self
- [ ] Falling squares

#### Fenwick Tree (BIT)
- [ ] Implement BIT
- [ ] Range sum query
- [ ] Point update
- [ ] Count inversions

#### Advanced
- [ ] Merge sort tree concept
- [ ] 2D segment tree concept

### 📓 Short Notes Template
```markdown
## Phase 16 Notes

### Segment Tree Template
```python
class SegmentTree: 
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.build(arr, 0, 0, self.n - 1)
    
    def build(self, arr, node, start, end):
        if start == end:
            self.tree[node] = arr[start]
        else: 
            mid = (start + end) // 2
            self.build(arr, 2*node+1, start, mid)
            self.build(arr, 2*node+2, mid+1, end)
            self.tree[node] = self. tree[2*node+1] + self.tree[2*node+2]
    
    def query(self, node, start, end, l, r):
        if r < start or l > end:
            return 0
        if l <= start and end <= r: 
            return self.tree[node]
        mid = (start + end) // 2
        return self. query(2*node+1, start, mid, l, r) + \
               self.query(2*node+2, mid+1, end, l, r)
```

### Fenwick Tree Template
```python
class BIT:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)
    
    def update(self, i, delta):
        while i <= self. n:
            self.tree[i] += delta
            i += i & (-i)
    
    def query(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & (-i)
        return s
```

### Comparison
| Operation | Segment Tree | Fenwick Tree |
|-----------|-------------|--------------|
| Space | O(4n) | O(n) |
| Build | O(n) | O(n log n) |
| Query | O(log n) | O(log n) |
| Update | O(log n) | O(log n) |
| Range Update | Yes (lazy) | Limited |
```

---

## 📖 **PHASE 17: Bit Manipulation** (Week 47-48)

### 📝 Topics
```
□ Bit operations basics
□ Bit masking
□ Common bit tricks
```

### 🎯 Problems to Solve

#### Basics
- [ ] Check if ith bit is set
- [ ] Set the ith bit
- [ ] Clear the ith bit
- [ ] Toggle the ith bit
- [ ] Check power of 2
- [ ] Count set bits
- [ ] Count set bits 1 to N

#### Problems
- [ ] Single number (XOR)
- [ ] Single number II (appears once, others thrice)
- [ ] Single number III (two single numbers)
- [ ] Counting bits (0 to n)
- [ ] Reverse bits
- [ ] Missing number (XOR)
- [ ] Sum of two integers (without +)
- [ ] Divide two integers (without /)
- [ ] Power set using bits
- [ ] Find XOR of numbers in range
- [ ] Minimum XOR value pair
- [ ] Maximum AND value pair

### 📓 Short Notes Template
```markdown
## Phase 17 Notes

### Bit Operations
```python
# Check ith bit
(n >> i) & 1

# Set ith bit
n | (1 << i)

# Clear ith bit  
n & ~(1 << i)

# Toggle ith bit
n ^ (1 << i)

# Clear rightmost set bit
n & (n - 1)

# Get rightmost set bit
n & (-n)

# Check power of 2
n > 0 and (n & (n-1)) == 0
```

### Common XOR Properties
- a ^ a = 0
- a ^ 0 = a
- a ^ b ^ a = b
- XOR is associative and commutative

### Count Set Bits (Brian Kernighan)
```python
count = 0
while n:
    n &= (n - 1)
    count += 1
```
```

---

## 📖 **PHASE 18: Math & Number Theory** (Week 49-50)

### 📝 Topics
```
□ Modular arithmetic
□ Prime algorithms
□ Combinatorics
□ Advanced math
```

### 🎯 Problems to Solve

#### Modular Arithmetic
- [ ] Modular addition, subtraction, multiplication
- [ ] Modular exponentiation
- [ ] Modular inverse
- [ ] nCr % p (Lucas theorem)

#### Prime & Factorization
- [ ] Sieve of Eratosthenes (optimized)
- [ ] Segmented sieve
- [ ] Prime factorization (O(√n))
- [ ] SPF (Smallest Prime Factor) sieve
- [ ] Count divisors

#### Combinatorics
- [ ] nCr calculation
- [ ] Pascal's triangle
- [ ] Catalan numbers
- [ ] Derangements
- [ ] Stars and bars

#### GCD & LCM
- [ ] Extended Euclidean algorithm
- [ ] GCD of array
- [ ] LCM of array

### 📓 Short Notes Template
```markdown
## Phase 18 Notes

### Modular Arithmetic
```python
MOD = 10**9 + 7

# Modular exponentiation
def power(base, exp, mod):
    result = 1
    while exp: 
        if exp & 1:
            result = result * base % mod
        base = base * base % mod
        exp >>= 1
    return result

# Modular inverse (when mod is prime)
def mod_inverse(a, mod):
    return power(a, mod - 2, mod)
```

### nCr % p
```python
# Precompute factorials
fact = [1] * (n + 1)
for i in range(1, n + 1):
    fact[i] = fact[i-1] * i % MOD

def nCr(n, r):
    if r > n:  return 0
    return fact[n] * mod_inverse(fact[r], MOD) % MOD * mod_inverse(fact[n-r], MOD) % MOD
```

### Important Formulas
- Catalan:  C(n) = C(2n,n)/(n+1)
- Derangements: D(n) = (n-1)(D(n-1) + D(n-2))
- Euler's totient:  φ(n) = count of coprimes < n
```

---

## 📖 **PHASE 19: Contest Practice & Revision** (Week 51-52+)

### Weekly Schedule
```
Monday:     Revise 1 topic from Phase 1-6
Tuesday:   Revise 1 topic from Phase 7-12  
Wednesday: Revise 1 topic from Phase 13-18
Thursday:   Solve 5 random medium problems
Friday:    Solve 2-3 random hard problems
Saturday:  Virtual contest OR timed practice
Sunday:    Review mistakes, update notes
```

### Platforms for Practice
- LeetCode (daily challenge + contests)
- Codeforces (contests)
- AtCoder (contests)
- CodeChef (contests)
- GeeksForGeeks (topic-wise)

---

## 🔄 **REVISION CYCLE** (Repeat Forever)

### Monthly Cycle
```
Week 1: Phases 1-5 (Basics, Arrays, Hashing, Sliding Window, Sorting)
Week 2: Phases 6-9 (Recursion, Linked List, Stack/Queue, Trees)
Week 3: Phases 10-13 (Heaps, Graphs, DP)
Week 4: Phases 14-18 (Greedy, Tries, Segment Trees, Bits, Math)
```

### Quick Revision Checklist
```
□ Can I write the template from memory?
□ Can I identify the pattern from problem statement?
□ Can I explain the approach in 2 minutes?
□ Can I code it in 15-20 minutes? 
```

---

## 📊 **Tracking Template**

Create a spreadsheet with: 
```
| Problem Name | Topic | Difficulty | Status | Date Solved | Notes |
|--------------|-------|------------|--------|-------------|-------|
```

Status levels:
- 🔴 Couldn't solve
- 🟡 Solved with hints
- 🟢 Solved independently
- ⭐ Optimal solution

---

## 💡 **Key Tips**

1. **Don't skip basics** - Even if you know them, quick revision helps
2. **Understand, don't memorize** - Know WHY the pattern works
3. **Time yourself** - 20 min easy, 40 min medium, 60 min hard
4. **Review mistakes** - Keep an "error log"
5. **Teach others** - Best way to solidify knowledge
6. **Stay consistent** - 1-2 hours daily > 10 hours once a week

---

This roadmap will serve you for your entire career.  Start from Phase 1 if you're rusty, or jump to specific phases as needed.  Bookmark this and keep coming back!  🚀

Would you like me to create an issue in one of your repositories to track this roadmap, or do you want me to elaborate on any specific phase? 