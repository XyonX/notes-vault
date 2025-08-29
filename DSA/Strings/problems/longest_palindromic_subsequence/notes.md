# Longest Palindromic Subsequence

## Problem Description
Given a string `s`, find the length of the longest palindromic subsequence in `s`. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

## Solution Approaches

### Version 1: Backtracking with String Tracking
- **Approach**: Build all possible subsequences and check if they're palindromes
- **Features**: 
  - Tracks both the actual palindrome string and its length
  - Uses backtracking to explore all possibilities
- **Problem**: Exponential time complexity, exceeds time limits for large inputs

### Version 2: Recursive Length Only
- **Approach**: Only track the length of the longest palindromic subsequence
- **Features**: 
  - More efficient than Version 1 but still exponential
  - Uses recursion with two choices: include or exclude current character
- **Problem**: Still needs memoization for optimal performance

## Key Features
- Helper function `isPalindrome` to check if a string is a palindrome
- Two different implementations showing optimization progression
- Notes that DP solution is needed for optimal performance

## Code Implementation
The `longestPalindromeSubseq` function provides two versions of the solution, with Version 1 being more comprehensive but less efficient.

## Status
Attempted (needs DP optimization for better performance)