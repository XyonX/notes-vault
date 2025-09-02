# Set Matrix Zeroes

## Problem Statement
Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's. You must do it in place.

## Approach
This solution uses a space-optimized approach by utilizing the first row and first column of the matrix itself as markers instead of using additional space for tracking which rows and columns need to be zeroed.

## Solution Explanation
1. First, check if the first row and first column themselves contain any zeros, storing this information in boolean flags
2. Iterate through the matrix (excluding first row and column) and use the first cell of each row and column as a marker:
   - If matrix[i][j] is 0, set matrix[i][0] and matrix[0][j] to 0
3. Iterate through the matrix again (excluding first row and column) and zero out cells based on the markers:
   - If matrix[i][0] or matrix[0][j] is 0, set matrix[i][j] to 0
4. Finally, zero out the first row and column if needed based on the flags set in step 1

## Time Complexity
O(m * n) - We traverse the matrix a constant number of times

## Space Complexity
O(1) - Only using constant extra space for the boolean flags