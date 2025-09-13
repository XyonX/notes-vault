# Detect High Load Windows

## Description

Identify time periods when a system experiences high load based on a rolling average calculation. For each minute in the monitoring period, calculate the average load over the most recent window of minutes. If this average exceeds the specified threshold, include that minute in your results.

The function `detectHighLoadWindows` takes three inputs:
- `vector&lt;int&gt;&amp; loads`: system load at each minute i (0-based)
- `int windowSize`: size of the rolling window in minutes
- `int threshold`: average load threshold to compare against

Returns a vector of starting indices of windows where the average load is greater than or equal to the threshold.

## Approach

Uses sliding window technique:
- Compute the initial sum of the first `windowSize` elements.
- Check if `windowSum >= threshold * windowSize` (using integer comparison to avoid floating point).
- For subsequent windows, subtract the outgoing element and add the incoming one, updating the sum in O(1) time.
- Use `long long` for `windowSum` to prevent integer overflow.

Time Complexity: O(n), where n is the size of loads.  
Space Complexity: O(1) for the sum, O(k) for result where k is number of qualifying windows.

## Notes

- The code includes a main function with 12 test cases covering basic cases, edge cases (window > array size, window=1, negatives, overflow risks), and boundary conditions.
- Key insight from code: Multiply threshold by windowSize and compare with sum to check average without division; use `1LL` cast for overflow safety.
- Similar to LeetCode Problem 1343: [Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/). The main difference is this returns indices instead of count, but the core sliding window logic is identical.

## Status
solved