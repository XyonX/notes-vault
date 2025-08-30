# Minimum Cost Climbing Stairs

## Problem
Find the minimum cost to reach the top of the floor where you can start from either step 0 or step 1. You can climb either 1 or 2 steps at a time.

## Approach
- Bottom-up DP where each step cost includes the minimum of the previous two steps
- The final answer is the minimum of the last two steps since you can end at either
- Base cases: cost[0] and cost[1] are the starting points

## Solution
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n <= 1) return 0;
        
        vector<int>dp(n);
        
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]= cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};
```

## Space Optimized Solution
```cpp
class SolutionOptimized {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n <= 1) return 0;
        
        int a = cost[0];
        int b = cost[1];
        
        for(int i=2;i<n;i++){
            int current = cost[i] + min(a, b);
            a = b;
            b = current;
        }
        return min(a, b);
    }
};
```

## Key Concepts
- **Bottom-up approach**: Start with base cases and build up to the solution
- **Tabulation**: Use arrays to store intermediate results
- **State transition**: dp[i] = cost[i] + min(dp[i-1], dp[i-2])
- **Final decision**: The answer is min(dp[n-1], dp[n-2]) since you can end at either step
- **Space optimization**: Can reduce space complexity from O(n) to O(1)

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(n) (can be optimized to O(1))

## Practice Status
- **Status**: Solved
- **Practice Count**: 1

## LeetCode Link
- [Minimum Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)

## Notes
- This problem demonstrates how to make decisions based on previous states
- The space optimized version shows how to reduce memory usage while maintaining the same logic
- Important to understand that you can start from either step 0 or step 1
- The final answer comes from the minimum of the last two steps since you can jump to the top from either