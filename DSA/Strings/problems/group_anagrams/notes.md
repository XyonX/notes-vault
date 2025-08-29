# Group Anagrams

## Problem Description
Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

## Solution Approach
The solution uses a hash map to group anagrams by their sorted character signatures:

1. **Create Hash Map**: Use a map where the key is the sorted version of each string
2. **Group Anagrams**: Strings that are anagrams will have the same sorted version
3. **Collect Results**: Extract all groups from the map and return them as a vector of vectors

## Key Features
- Efficient grouping using sorted strings as keys
- Handles strings of varying lengths
- Time Complexity: O(n * k log k) where n is number of strings and k is maximum string length
- Space Complexity: O(n * k) to store all strings

## Code Implementation
The `groupAnagrams` function implements the sorting approach with a helper function `displayStrings` for output.

## Status
Solved