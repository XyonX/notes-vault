// Unique Paths in Grid (DP)
// Problem: Count unique paths from (0, 0) to (n-1, n-1) in an n x n grid, moving only right or down
// Approach: Dynamic programming with memoization
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) for memoization table

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Basic recursive solution (inefficient - exponential time)
int numGridUniquePath(int i, int j, int n, vector<vector<int>>& grid) {
    if(i == n-1 && j == n-1) return 1;
    if(i > n-1 || j > n-1) return 0;
    
    int bottom = numGridUniquePath(i+1, j, n, grid);
    int right = numGridUniquePath(i, j+1, n, grid);
    
    return bottom + right;
}

// Memoized DP solution (efficient)
int numGUP(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(i == n-1 && j == n-1) return 1;
    if(i > n-1 || j > n-1) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int bottom = numGUP(i+1, j, n, grid, dp);
    int right = numGUP(i, j+1, n, grid, dp);
    
    return dp[i][j] = bottom + right;
}

// Tabulation solution (bottom-up DP)
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

// Space optimized tabulation solution
int numGridUniquePathOptimized(int n) {
    vector<int> dp(n, 1);
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j-1];
        }
    }
    
    return dp[n-1];
}

int main() {
    int n = 4;
    vector<vector<int>> grid(n, vector<int>(n));
    
    // Initialize grid with sample values
    int count = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            grid[i][j] = count++;
        }
    }
    
    cout << "Grid size: " << n << "x" << n << endl;
    
    // Basic recursive (only for small grids)
    cout << "Basic recursive paths: " << numGridUniquePath(0, 0, n, grid) << endl;
    
    // Memoized DP
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoized DP paths: " << numGUP(0, 0, n, grid, dp) << endl;
    
    // Tabulation DP
    cout << "Tabulation DP paths: " << numGridUniquePathTabulation(n) << endl;
    
    // Space optimized DP
    cout << "Space optimized DP paths: " << numGridUniquePathOptimized(n) << endl;
    
    return 0;
}