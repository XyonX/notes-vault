# Fibonacci Sequence (DP)

## Problem
Calculate the nth Fibonacci number using dynamic programming.

## Approach
- Bottom-up DP with tabulation
- Start with base cases and build up to the solution
- Use arrays to store intermediate results

## Solution
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

## Key Concepts
- **Bottom-up approach**: Start with base cases and build up to the solution
- **Tabulation**: Use arrays to store intermediate results
- **State transition**: Each state depends on previous states
- **Base cases**: Essential for starting the DP solution

## Complexity Analysis
- **Time Complexity**: O(n)
- **Space Complexity**: O(n)

## Practice Status
- **Status**: Solved
- **Practice Count**: 1

## Notes
- This is a classic DP problem that demonstrates the fundamental concepts of dynamic programming
- The solution can be optimized to O(1) space by only keeping track of the last two values