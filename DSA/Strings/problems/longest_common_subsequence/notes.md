# Longest Common Subsequence

## Problem Description
Given two strings `text1` and `text2`, return the length of their longest common subsequence. A subsequence is a sequence that appears in the same relative order but not necessarily contiguous.

## Solution Approaches

### 1. Recursive Approach (Without Memoization)
- **Base Case**: If either string is empty, return 0
- **Recursive Case**: 
  - If characters match, move both pointers forward and add 1
  - If characters don't match, take max of moving either pointer forward
- **Problem**: Exponential time complexity O(2^(m+n))

### 2. Dynamic Programming (With Memoization)
- **DP Table**: 2D vector initialized with -1
- **Base Case**: If either pointer is negative, return 0
- **Memoization**: Store computed results to avoid redundant calculations
- **Time Complexity**: O(m*n) where m and n are string lengths
- **Space Complexity**: O(m*n) for DP table

## Key Features
- Handles empty strings gracefully
- Efficient solution using dynamic programming
- Comprehensive test cases covering various scenarios

## Code Implementation
The `longestCommonSubsequence` function implements the DP approach with memoization.

## Status
Solved