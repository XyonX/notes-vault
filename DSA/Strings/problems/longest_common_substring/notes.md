# Longest Common Substring

## Problem Statement
Given two strings, find the longest common substring between them. A substring is a contiguous sequence of characters within a string.

## Approach
Two recursive approaches are implemented:

1. First approach (content1.cpp):
   - Uses a helper function with additional parameters to build the current substring
   - Requires reversing the result at the end
   - Explores all possible paths by opening two branches when characters don't match

2. Second approach (content2.cpp):
   - More straightforward recursive approach that builds the substring as it recurses
   - No need to reverse the result
   - Returns the longer of two possible substrings when characters don't match

## Solution Explanation
Both solutions use recursion to explore all possible common substrings:
- When characters match, we include the character and recurse on the remaining substrings
- When characters don't match, we explore both possibilities:
  - Skip a character from the first string
  - Skip a character from the second string
- Base case: When either string is empty, return the current substring (or empty string)

## Time Complexity
O(2^(m+n)) where m and n are the lengths of the two strings - exponential due to exploring all possible paths

## Space Complexity
O(m+n) for the recursion stack depth

## Known Issues
- Both implementations have exponential time complexity and are not efficient for large inputs
- A dynamic programming approach would be more efficient with O(m*n) time complexity