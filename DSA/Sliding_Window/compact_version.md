# Compact Version: Sliding Window

## detect_high_load_windows

- **Problem**: Detect starting indices of windows where the average load >= threshold using sliding window.
- **Approach**: Maintain a running sum of the window. For each position, check if sum >= threshold * windowSize. Slide by subtracting left and adding right.
- **Edge Cases Handled**: Window larger than array (return empty), negatives, overflow with long long, window size 1, exact threshold match.
- **Complexity**: Time O(n), Space O(1) excluding output.
- **LeetCode Similar**: 1343 - Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold (modify to return indices instead of count).