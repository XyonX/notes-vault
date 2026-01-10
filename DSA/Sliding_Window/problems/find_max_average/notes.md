# find_max_average

## Solution
Uses sliding window to initialize sum of first k elements, then slides the window by subtracting the left element and adding the new right element, tracking the maximum average at each step.

## Notes
- Time Complexity: O(n) where n is the length of nums.
- Space Complexity: O(1).
- Key Insight: Average = sum / k; maintain running sum to avoid O(k) per window.
- Edge Cases: When k equals nums.size() (single window), or all negative numbers (still works as max handles it).
- This solves LeetCode 643 efficiently.

## LeetCode Link
[Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/) (Easy)

Status: solved
