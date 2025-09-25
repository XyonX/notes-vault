# longest_subarray_same_elements

## Solution
Two-pointer technique: Initialize l=0, iterate r from 1, reset l to r when arr[r] != arr[r-1], track max(r - l + 1).

## Notes
- Time: O(n), Space: O(1).
- Handles empty array (return 0), single element (1), all same (n), all unique (1).
- Tests included: All same (4), no repeats (1), mixed (3), etc. - all pass.
- Generalizes LeetCode 485 for any element, not just 1s.

## LeetCode Link
[Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) (Easy) - Similar concept.

Status: solved
