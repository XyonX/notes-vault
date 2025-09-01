# Next Greater Element

## Problem Statement
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in the array. Elements for which no greater element exist, consider the next greater element as -1.

## Approach
This solution uses a stack data structure to efficiently find the next greater element for each element in the array:
1. Traverse the array from right to left
2. For each element:
   - Pop elements from the stack while the top of the stack is less than or equal to the current element
   - If the stack is empty, the next greater element is -1
   - Otherwise, the next greater element is the top of the stack
   - Push the current element onto the stack

## Time Complexity
O(n) where n is the number of elements in the array. Each element is pushed and popped from the stack at most once.

## Space Complexity
O(n) for the stack and result array.

## Key Points
- This is a classic stack problem that demonstrates the monotonic stack pattern
- The algorithm processes elements from right to left to efficiently compute the next greater elements
- The stack maintains a decreasing sequence of elements from bottom to top

## LeetCode Link
[Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
[Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/)