# Unique Paths in Grid (DP)

## Problem Statement
Given a grid of size `n x n`, count the number of unique paths from the top-left corner `(0, 0)` to the bottom-right corner `(n-1, n-1)`. You can only move **right** or **down**.

## Approaches

### 1. Recursive Solution
- **Base Case**: If the current position is `(n-1, n-1)`, return `1` (reached the destination).
- **Edge Case**: If the current position is out of bounds, return `0`.
- **Recursive Calls**: Sum the paths from moving right and moving down.
- **Time Complexity**: Exponential (`O(2^n)`).
- **Space Complexity**: O(n) for recursion stack.

### 2. Memoized DP Solution
- Uses a `dp` table to store intermediate results and avoid redundant calculations.
- **Time Complexity**: `O(n^2)`.
- **Space Complexity**: `O(n^2)` for the memoization table.

### 3. Tabulation (Bottom-up DP)
- Build the solution iteratively from base cases.
- **Base Cases**: First row and first column have only one path each.
- **Recurrence Relation**: `dp[i][j] = dp[i-1][j] + dp[i][j-1]`
- **Time Complexity**: `O(n^2)`.
- **Space Complexity**: `O(n^2)`.

### 4. Space Optimized Tabulation
- Recognize that we only need the previous row to compute the current row.
- **Time Complexity**: `O(n^2)`.
- **Space Complexity**: `O(n)`.

## Solutions

### Recursive Solution
```cpp
int numGridUniquePath(int i, int j, int n, vector<vector<int>>& grid) {
    if(i == n-1 && j == n-1) return 1;
    if(i > n-1 || j > n-1) return 0;
    
    int bottom = numGridUniquePath(i+1, j, n, grid);
    int right = numGridUniquePath(i, j+1, n, grid);
    
    return bottom + right;
}
```

### Memoized DP Solution
```cpp
int numGUP(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(i == n-1 && j == n-1) return 1;
    if(i > n-1 || j > n-1) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int bottom = numGUP(i+1, j, n, grid, dp);
    int right = numGUP(i, j+1, n, grid, dp);
    
    return dp[i][j] = bottom + right;
}
```

### Tabulation Solution
```cpp
int numGridUniquePathTabulation(int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Base case: first row and first column have only one path
    for(int i = 0; i < n; i++) {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    
    // Fill the DP table
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[n-1][n-1];
}
```

### Space Optimized Solution
```cpp
int numGridUniquePathOptimized(int n) {
    vector<int> dp(n, 1);
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j-1];
        }
    }
    
    return dp[n-1];
}
```

## Key Concepts Demonstrated
1. **Overlapping Subproblems**: The same subproblems are solved multiple times in the recursive approach.
2. **Optimal Substructure**: The solution can be constructed from solutions to subproblems.
3. **Memoization**: Top-down approach with caching to avoid redundant calculations.
4. **Tabulation**: Bottom-up approach building solutions from base cases.
5. **Space Optimization**: Recognizing patterns to reduce space complexity.

## Complexity Analysis
| Approach | Time Complexity | Space Complexity |
|----------|----------------|------------------|
| Recursive | O(2^(2n)) | O(n) |
| Memoized | O(n^2) | O(n^2) |
| Tabulation | O(n^2) | O(n^2) |
| Space Optimized | O(n^2) | O(n) |

## Practice Status
- **Status**: Solved
- **Practice Count**: 1

## Notes
- The recursive solution is only practical for very small grids (n ≤ 15)
- The memoized version is much more efficient for larger grids
- The tabulation approach avoids recursion stack overhead
- The space optimized version is the most efficient in terms of memory usage
- This problem can also be solved using combinatorics (choosing (n-1) right moves and (n-1) down moves from 2n-2 total moves)

## Variations
- Grid with obstacles: Some cells may be blocked, requiring additional checks
- Different movement constraints: Allow diagonal moves or other directions
- Rectangular grids: Instead of n x n, use m x n grids