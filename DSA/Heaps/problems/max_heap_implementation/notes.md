# Max Heap Implementation

## LeetCode Link
No specific LeetCode problem; fundamental data structure for priority queues (e.g., used in LeetCode #23: Merge k Sorted Lists, #215: Kth Largest Element).

## Approach
Custom max heap class using vector for storage. Supports insertion with heapify-up to maintain max-heap property (parent >= children).

- Insert: Add to end, then swap with parent if violates heap property, repeat until heapified.
- Array indices: Parent of i is (i-1)/2, left child 2i+1, right 2i+2.

## Time Complexity
- Insert: O(log n) average/worst (height of heap).

## Space Complexity
O(n) for storing elements.

## Key Learnings
- Heaps are complete binary trees satisfying heap property.
- Max heap: Root is maximum element.
- Build full heap (insert + delete-min) in O(n), but insert/delete each O(log n).
- Use priority_queue in C++ STL for quick max heap (priority_queue<int>).

## Practice Count
1 (Practiced on 2025-09-12)

## Status
solved
