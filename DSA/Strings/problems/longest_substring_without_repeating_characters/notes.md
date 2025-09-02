# Longest Substring Without Repeating Characters

## Problem Statement
Given a string s, find the length of the longest substring without repeating characters.

## Approach
This solution uses the sliding window technique with two pointers (left and right) and a frequency array to track the last seen index of each character.

## Solution Explanation
1. Use a frequency array of size 256 (for all ASCII characters) initialized to -1 to store the last seen index of each character
2. Maintain two pointers: left (l) for the start of the current window and right (r) for the end
3. For each character at position r:
   - If the character was seen before and its last seen index is within the current window (>= l), move the left pointer to the position after the last occurrence
   - Update the maximum length if the current window is larger
   - Update the last seen index of the current character to r
4. Return the maximum length found

## Time Complexity
O(n) - We traverse the string once

## Space Complexity
O(1) - We use a fixed-size array of 256 elements regardless of input size