# Discussion: Sliding Window

## detect_high_load_windows

### Problem Understanding
This problem involves monitoring system load over time and detecting periods where the average load over a sliding window of minutes exceeds a given threshold. We return the starting indices (minutes) where such high-load windows begin. It's a classic sliding window application for efficient average computation without recalculating from scratch each time.

### Key Insights
- **Average Check Without Division**: To avoid floating-point precision issues, compare the window sum directly against `threshold * windowSize`. Since loads are integers, this works for integer thresholds.
- **Overflow Prevention**: Use `long long` for `windowSum` because summing large integers (up to 10^9 as in test cases) can exceed `int` limits (2^31-1). The code correctly casts with `1LL * threshold * windowSize`.
- **Edge Cases**:
  - If `loads.size() < windowSize`, return empty vector (no full windows possible).
  - Window size 1: Simply checks if each load >= threshold.
  - Negative loads: Handled naturally since comparison is on sum vs. threshold * size.
  - Exact match: Uses `>=` so includes windows where average exactly equals threshold.
  - Invalid windowSize=0: The code doesn't explicitly handle, but loop won't run; consider adding check if needed.
- **Test Cases Coverage**: The provided main() tests a wide range: basic sliding, all high, all low, exact size, too small, border cases, negatives, overflow risks, window=1, alternating patterns. This ensures robustness.

### Relation to LeetCode 1343
This is nearly identical to LeetCode 1343, but instead of counting qualifying subarrays, we collect their starting indices. The sliding window logic is the same. In interviews, mention this problem to show pattern recognition—sliding window for subarray averages is common.

### Potential Interview Questions
- How would you modify for floating-point threshold? (Use division but handle precision, e.g., with epsilon.)
- What if windows overlap and you need consecutive high-load periods? (Post-process results to merge adjacent indices.)
- Optimize space if n is huge? (Already O(1) space excluding output; output could be O(n) worst-case.)
- Extend to 2D loads (e.g., multi-server)? (Nested sliding windows or prefix sums.)

### Common Mistakes
- Forgetting overflow: Without `long long`, large inputs crash or give wrong results.
- Off-by-one in sliding: Ensure `i <= loads.size() - windowSize` for the loop.
- Initial window check: Code correctly pushes 0 if first window qualifies.

### Practice Tips
Implement in other languages (Python, Java) for comparison. Time it on large inputs (n=10^5) to verify O(n). Discuss trade-offs: Prefix sums alternative is O(n) time but O(n) space vs. this O(1) space.