# Parenthesis Checker

## Problem Statement
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

## Approach
This solution uses a stack data structure to validate the parentheses:
1. Iterate through each character in the string
2. If an opening bracket is encountered, push it onto the stack
3. If a closing bracket is encountered:
   - Check if the stack is empty; if so, return false
   - Check if the top element matches the current closing bracket
   - If matching, pop the element from the stack
   - If not matching, return false
4. After processing all characters, if the stack is not empty, return false
5. Otherwise, return true

## Enhanced Features in New Implementation
- Fixed the typo in function name: "balancePranthesis" → "balanceParenthesis"
- Improved code readability with better comments
- Added handling for non-bracket characters (they are ignored rather than causing failure)
- Added comprehensive test cases including edge cases and mixed content

## Time Complexity
O(n) where n is the length of the string

## Space Complexity
O(n) in the worst case when all characters are opening brackets

## LeetCode Link
[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)