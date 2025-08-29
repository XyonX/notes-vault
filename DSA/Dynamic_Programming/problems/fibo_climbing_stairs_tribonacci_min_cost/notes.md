# Fibonacci, Climbing Stairs, Tribonacci, and Minimum Cost Climbing Stairs

## Problems Covered
1. Fibonacci Sequence (DP)
2. Climbing Stairs (LeetCode 70)
3. Nth Tribonacci Number (LeetCode 1137)
4. Minimum Cost Climbing Stairs (DP)

## Solutions

### Fibonacci Sequence
- **Problem**: Calculate the nth Fibonacci number using dynamic programming
- **Approach**: Bottom-up DP with tabulation
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

```cpp
int fibo(int n){
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
```

### Climbing Stairs (LeetCode 70)
- **Problem**: Count the number of ways to reach the nth stair if you can climb either 1 or 2 stairs at a time
- **Approach**: Similar to Fibonacci, bottom-up DP
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

```cpp
int climbingStares(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
```

### Nth Tribonacci Number (LeetCode 1137)
- **Problem**: Calculate the nth Tribonacci number where each term is the sum of the three preceding terms
- **Approach**: Bottom-up DP with three base cases
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

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

### Minimum Cost Climbing Stairs
- **Problem**: Find the minimum cost to reach the top of the floor where you can start from either step 0 or step 1
- **Approach**: Bottom-up DP where each step cost includes the minimum of the previous two steps
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
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

## Key DP Concepts Demonstrated
1. **Bottom-up approach**: Start with base cases and build up to the solution
2. **Tabulation**: Use arrays to store intermediate results
3. **State transition**: Each state depends on previous states
4. **Base cases**: Essential for starting the DP solution

## Practice Status
- **Status**: Solved
- **Practice Count**: 1

## LeetCode Links
- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [Nth Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/)
- [Minimum Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)