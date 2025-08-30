# Nth Tribonacci Number (LeetCode 1137)

## Problem
Calculate the nth Tribonacci number where each term is the sum of the three preceding terms.

## Approach
- Bottom-up DP with three base cases
- Similar to Fibonacci but with three previous terms instead of two
- Base cases: T(0) = 0, T(1) = 1, T(2) = 1

## Solution
```cpp
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};
```

## Space Optimized Solution
```cpp
class SolutionOptimized {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        int a = 0, b = 1, c = 1;
        for(int i=3;i<=n;i++){
            int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }
};
```

## Key Concepts
- **Bottom-up approach**: Start with base cases and build up to the solution
- **Tabulation**: Use arrays to store intermediate results
- **State transition**: T(n) = T(n-1) + T(n-2) + T(n-3)
- **Base cases**: Essential for starting the DP solution
- **Space optimization**: Can reduce space complexity from O(n) to O(1)

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) (can be optimized to O(1))

## Practice Status
- **Status**: Solved
- **Practice Count**: 1

## LeetCode Link
- [Nth Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/)

## Notes
- This problem extends the Fibonacci concept to three previous terms
- The space optimized version demonstrates how to reduce memory usage
- Important to handle edge cases (n = 0, 1, 2) separately