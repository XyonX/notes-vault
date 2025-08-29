# Dynamic Programming Discussion

## Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top. You can either climb 1 or 2 steps at a time. How many distinct ways can you climb to the top?

This is a classic dynamic programming problem that follows the Fibonacci sequence. The key insight is that to reach step n, you can come from either step n-1 (by taking 1 step) or step n-2 (by taking 2 steps).

Two recursive implementations were explored:
1. One that returns the count directly
2. One that uses a reference parameter to accumulate the count

For n=15, there are 987 distinct ways to climb to the top, with the base cases being hit 987 times, confirming our intuition that each base case hit represents one distinct path.

## Frog Jump
This problem is a variation of the classic climbing stairs problem. Instead of counting the number of ways to reach the top, we're minimizing the energy cost based on height differences between stairs.

The key insight is that to reach stair i, we can come from either stair i-1 or i-2, and we want to choose the path that minimizes the total energy cost. The energy cost of a jump from stair j to stair i is the absolute difference in their heights.

Two implementations were explored:
1. A recursive approach without memoization (exponential time complexity)
2. A memoized recursive approach (linear time complexity)

The base cases are:
- Cost to reach stair 0 is 0
- Cost to reach stair 1 is the absolute difference between heights[1] and heights[0]

For any other stair i, the minimum cost is:
min(frogJump(i-1) + abs(heights[i] - heights[i-1]), frogJump(i-2) + abs(heights[i] - heights[i-2]))

## Fibonacci, Tribonacci, and Minimum Cost Problems
This collection demonstrates fundamental DP patterns:

### Fibonacci Sequence
The classic DP problem where each number is the sum of the two preceding ones. The bottom-up approach efficiently computes the nth Fibonacci number by iteratively building the solution from base cases.

### Tribonacci Number
An extension of Fibonacci where each term is the sum of the three preceding terms. This shows how easily DP patterns can be extended to different recurrence relations.

### Minimum Cost Climbing Stairs
A cost-optimization variant where you can start from either step 0 or 1, and each step has an associated cost. The solution involves finding the path with minimum total cost to reach beyond the last step.

### Key DP Patterns Demonstrated
1. **Bottom-up Tabulation**: Building solutions from base cases iteratively
2. **State Transition**: Defining how each state depends on previous states
3. **Space Optimization**: While these examples use O(n) space, many can be optimized to O(1) by recognizing that only the last few states are needed
4. **Multiple Base Cases**: Handling problems with more than one base case (like Tribonacci with three base cases)

### Common Pitfalls
- Forgetting to handle edge cases (n=0, n=1, n=2)
- Incorrectly defining the recurrence relation
- Not considering space optimization opportunities
- Mixing up 0-based and 1-based indexing