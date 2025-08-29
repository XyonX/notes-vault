# Valid Anagram

## Problem Description
Given two strings `s1` and `s2`, determine if `s2` is an anagram of `s1`.

## Solution Approach
The solution uses a frequency array to count character occurrences:

1. **Check Lengths**: If the strings have different lengths, they can't be anagrams
2. **Frequency Counting**: Use a vector of size 26 (for each letter) to count character frequencies
3. **Case Handling**: Convert characters to lowercase for case-insensitive comparison
4. **Validation**: Check if all frequency counts are zero

## Key Features
- Handles both uppercase and lowercase characters
- Validates input to ensure only alphabetic characters are processed
- Time Complexity: O(n) where n is the length of the strings
- Space Complexity: O(1) (fixed size array of 26 elements)

## Code Implementation
The `validAnagram` function implements the frequency counting approach efficiently.

## Status
Solved