# Dynamic Programming Discussion

## Fibonacci Sequence
The classic DP problem where each number is the sum of the two preceding ones. The bottom-up approach efficiently computes the nth Fibonacci number by iteratively building the solution from base cases.

**Key Insights:**
- Base cases: fib(0) = 0, fib(1) = 1
- Recurrence relation: fib(n) = fib(n-1) + fib(n-2)
- Can be optimized to O(1) space by tracking only the last two values

## Climbing Stairs (LeetCode 70)
You are climbing a staircase. It takes n steps to reach the top. You can either climb 1 or 2 steps at a time. How many distinct ways can you climb to the top?

This is a classic dynamic programming problem that follows the Fibonacci sequence. The key insight is that to reach step n, you can come from either step n-1 (by taking 1 step) or step n-2 (by taking 2 steps).

**Key Insights:**
- Base cases: ways(0) = 1, ways(1) = 1
- Recurrence relation: ways(n) = ways(n-1) + ways(n-2)
- For n=15, there are 987 distinct ways to climb to the top

## Tribonacci Number (LeetCode 1137)
Calculate the nth Tribonacci number where each term is the sum of the three preceding terms.

This extends the Fibonacci concept to three previous terms, demonstrating how DP patterns can be easily extended to different recurrence relations.

**Key Insights:**
- Base cases: trib(0) = 0, trib(1) = 1, trib(2) = 1
- Recurrence relation: trib(n) = trib(n-1) + trib(n-2) + trib(n-3)
- Can be optimized to O(1) space by tracking the last three values

## Minimum Cost Climbing Stairs
Find the minimum cost to reach the top of the floor where you can start from either step 0 or step 1. Each step has an associated cost, and you can climb 1 or 2 steps at a time.

This is a cost-optimization variant where the solution involves finding the path with minimum total cost to reach beyond the last step.

**Key Insights:**
- Base cases: cost[0] and cost[1] are the starting points
- Recurrence relation: dp[i] = cost[i] + min(dp[i-1], dp[i-2])
- Final answer: min(dp[n-1], dp[n-2]) since you can end at either step

## Frog Jump
This problem is a variation of the classic climbing stairs problem. Instead of counting the number of ways to reach the top, we're minimizing the energy cost based on height differences between stairs.

**Key Insights:**
- To reach stair i, you can come from either stair i-1 or i-2
- Energy cost of a jump from stair j to stair i is the absolute difference in their heights
- Base cases: cost to reach stair 0 is 0, cost to reach stair 1 is abs(heights[1] - heights[0])

## Grid-Based DP
**Unique Paths in Grid**: A classic DP problem where we count paths in a grid with movement constraints (right/down). This demonstrates how DP can be applied to 2D problems.

**Key Insights:**
- Movement constraints: only right and down directions allowed
- Recurrence relation: dp[i][j] = dp[i-1][j] + dp[i][j-1]
- Base cases: first row and first column have only one path each
- Can be solved with recursion + memoization or bottom-up tabulation
- Multiple optimization approaches available: O(n^2) space can be reduced to O(n)

### Unique Paths in Grid (Detailed)
This problem demonstrates several important DP concepts:
1. **2D State Representation**: Using dp[i][j] to represent paths to position (i,j)
2. **Multiple Approaches**: From exponential recursive to O(n) space optimized
3. **Base Case Handling**: Proper initialization of first row and column
4. **Space Optimization**: Recognizing that only the previous row is needed

**Approaches Demonstrated:**
- **Recursive**: Simple but exponential time complexity
- **Memoized**: Top-down DP with caching
- **Tabulation**: Bottom-up DP with O(n^2) space
- **Space Optimized**: Bottom-up DP with O(n) space

## General DP Patterns
1. **Tabulation vs. Memoization**: Bottom-up vs. top-down approaches
2. **Optimal Substructure**: Optimal solution can be constructed from optimal solutions of subproblems
3. **Overlapping Subproblems**: Same subproblems are solved multiple times (key indicator for DP)
4. **State Definition**: Carefully defining what each state represents
5. **Transition**: How to move from one state to another

## Common Pitfalls
- Forgetting to handle edge cases (n=0, n=1, n=2)
- Incorrectly defining the recurrence relation
- Not considering space optimization opportunities
- Mixing up 0-based and 1-based indexing
- Forgetting that you can start from different positions (like in minimum cost climbing stairs)
- Not properly initializing base cases in 2D DP problems
- Using incorrect dimensions for DP arrays