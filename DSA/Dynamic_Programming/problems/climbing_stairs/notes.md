# Climbing Stairs (LeetCode 70)

## Problem
Count the number of ways to reach the nth stair if you can climb either 1 or 2 stairs at a time.

## Approach
- Similar to Fibonacci sequence, bottom-up DP
- Each step can be reached from either the previous step (i-1) or the step before that (i-2)
- Base cases: 0 stairs = 1 way (do nothing), 1 stair = 1 way (climb 1)

## Solution
```cpp
int climbingStairs(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
```

## Key Concepts
- **Bottom-up approach**: Start with base cases and build up to the solution
- **Tabulation**: Use arrays to store intermediate results
- **State transition**: ways[i] = ways[i-1] + ways[i-2]
- **Base cases**: Essential for starting the DP solution

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Practice Status
- **Status**: Solved
- **Practice Count**: 1

## LeetCode Link
- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)

## Notes
- This problem demonstrates how real-world problems can be modeled using DP
- The solution can be optimized to O(1) space by only keeping track of the last two values
- This is a fundamental DP problem that appears frequently in technical interviews