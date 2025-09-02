# Remove Duplicates from Sorted Array

## Problem Statement
Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length. The relative order of the elements should be kept the same.

## Approach
This solution uses the two-pointer technique (slow and fast pointers) to remove duplicates in-place.

## Solution Explanation
1. Initialize a slow pointer (s) at index 0
2. Initialize a fast pointer (f) at index 1
3. Iterate through the array with the fast pointer:
   - If the element at the fast pointer is different from the element at the slow pointer:
     - Move the slow pointer one step forward
     - Copy the element at the fast pointer to the position of the slow pointer
4. Return slow pointer position + 1 (which represents the new length of the array)

## Time Complexity
O(n) - We traverse the array once

## Space Complexity
O(1) - We modify the array in-place using only constant extra space