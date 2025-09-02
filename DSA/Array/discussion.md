## find_mode_of_array

- Find the mode of an array.

## variance_of_array

- Find the variance of an array. Known Issues: This problem was not fully implemented. Will do it later.

## kadanes_algorithm

- Find the maximum subarray sum (Kadane's algorithm).

## sort_colors

- Dutch National Flag problem to sort 0s, 1s, and 2s using three pointers (l, m, r). Current code is an attempted version with a comparison bug (`el=2`) and pointer handling detail after swapping with `r`.

## min_subarray_sum

- Find the minimum subarray sum.

## max_sum_non_adjacent_elements

- Find the maximum sum subarray with non-adjacent elements. Known Issues: Memoization is not yet implemented for this recursive solution.

## max_subarray_sum_min_length

- Find the subarray with the maximum sum and minimum length.

## min_sum_max_length

- Find the subarray with the minimum sum and maximum length.

## find_subarray_with_given_sum

- This problem, "Subarray Sum Equals K", is a classic array manipulation problem. The goal is to find a contiguous subarray whose elements sum up to a given target value.

There are two common approaches to solving this problem:

1.  **Sliding Window:** This approach is efficient but only works for arrays with all positive numbers. It involves maintaining a "window" of elements and expanding or shrinking it to find the target sum.

2.  **Prefix Sum with Hashmap:** This is a more versatile approach that works for arrays with both positive and negative numbers. It involves calculating the prefix sum at each index and using a hashmap to quickly check if a subarray with the target sum exists.

[LeetCode Problem: Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

## rotate_array_right
- This problem discusses array rotation to the right by `k` positions. Both a brute-force approach and an optimal in-place solution using the reversal algorithm are presented.

**Brute-Force Discussion:**
This method involves creating a new array and copying elements in the desired rotated order. While straightforward, its main drawback is the additional space complexity of O(N), which can be significant for large arrays.

**Optimal Solution (Reversal Algorithm) Discussion:**
This in-place technique is highly efficient. It leverages the property that reversing parts of the array and then the whole array achieves the desired rotation. The three steps (reverse last k, reverse first n-k, reverse whole array) ensure that the elements are moved to their correct positions without requiring extra space. This makes it a preferred solution for competitive programming and real-world scenarios where memory optimization is crucial.

## migratory_birds
- This problem involves finding the most frequently sighted bird type from an array of sightings. The solution uses a frequency map to count occurrences of each bird type, then iterates through the array to find the bird type with the highest frequency. In case of a tie, it returns the smallest id.

## bill_division
- This problem involves calculating the correct share for Anna in a bill split scenario. The solution sums all items except the one Anna didn't eat, divides by 2 to get her correct share, and compares with Brian's calculation. If they match, it outputs "Bon Appetit"; otherwise, it shows the difference.

## sock_merchant
- This problem involves counting pairs of socks with matching colors. The solution uses a frequency map to count occurrences of each sock color, then calculates the number of pairs by dividing each count by 2 and summing the results.

## generate_non_adjacent_subsequences
- This problem involves generating all possible subsequences from an array where no two elements are adjacent in the original array. It demonstrates the use of recursion and backtracking to explore all valid combinations. The solution includes two implementations: one incorrect approach that tries to skip elements at odd indices, and a correct approach that properly handles non-adjacent element selection by skipping the next element when including the current one.

## electronics_shop
- This problem involves finding the maximum sum of one keyboard and one USB drive that doesn't exceed a given budget. The solution uses a brute force approach with some optimizations:
  1. Sort keyboards in descending order and drives in ascending order
  2. For each keyboard, iterate through drives:
     - Calculate the cost of the combination
     - If the cost exceeds the budget, break (since drives are sorted, further drives will also exceed)
     - Keep track of the maximum valid cost found
- Time complexity: O(n*m) in the worst case, where n is the number of keyboards and m is the number of drives
- Space complexity: O(1) - only using a few variables

## two_sum
- This is a classic array problem where we need to find two numbers in an array that add up to a specific target. The optimal solution uses a hash map to store elements and their indices, allowing us to find the complement in O(1) time. This results in an overall time complexity of O(n) and space complexity of O(n).

[LeetCode Problem: Two Sum](https://leetcode.com/problems/two-sum/)

## three_sum
- This problem extends the Two Sum problem to find triplets that sum to zero. The optimal approach involves sorting the array first and then using a two-pointer technique. For each element, we fix it and use two pointers to find pairs that sum to the negative of the fixed element. Careful handling of duplicates is essential to avoid duplicate triplets in the result.

[LeetCode Problem: Three Sum](https://leetcode.com/problems/3sum/)

## majority_element
- This problem involves finding the majority element in an array, which is defined as the element that appears more than ⌊n/2⌋ times. The solution implements the Boyer-Moore Majority Vote Algorithm, which is an efficient O(n) time and O(1) space approach. The algorithm works by maintaining a candidate for the majority element and a counter, updating them as we iterate through the array.

## battle_of_warriors
- This is a custom variation of the Majority Element problem presented in a story format about warrior clans. The solution uses the same Boyer-Moore Majority Vote Algorithm, where warriors from the same clan unite (increment counter) and warriors from different clans duel and fall (decrement counter). The clan with more than half the warriors will survive all duels.

## max_profit
- This problem, "Best Time to Buy and Sell Stock", is a classic array optimization problem. The goal is to find the maximum profit that can be achieved by buying a stock on one day and selling it on a different day in the future.

Two approaches are commonly used:
1. **Brute Force:** Check all possible buy-sell combinations using nested loops. Time complexity: O(n²).
2. **Greedy Approach:** Keep track of the minimum price seen so far and calculate the maximum profit at each day. Time complexity: O(n). This is the optimal solution implemented in the code.

[LeetCode Problem: Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
## kth_smallest_element
- Discussed O(n log n) sort approach vs O(n log k) heap approach; included typical pitfalls and test coverage.

## running_sum
- This problem involves computing the running sum (prefix sum) of an array. The solution iterates through the array once, accumulating the sum at each position and storing it in a result vector. This is a fundamental array operation that serves as building block for more complex problems like range sum queries and subarray sum problems.

[LeetCode Problem: Running Sum of 1d Array](https://leetcode.com/problems/running-sum-of-1d-array/)

## largest_altitude
- This problem is a variation of the running sum problem where we need to find the maximum value in the prefix sum array. The solution computes the running sum while keeping track of the maximum value encountered. This demonstrates how prefix sum concepts can be extended to solve related optimization problems.

[LeetCode Problem: Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)

## pivot_index
- This problem involves finding a pivot index where the sum of elements to the left equals the sum of elements to the right. The solution uses prefix and suffix sum arrays to efficiently check each index. This problem demonstrates the power of prefix sums in solving array partitioning problems. An optimized version exists that uses O(1) space by computing the total sum first and then using a single pass with prefix sums.

[LeetCode Problem: Find Pivot Index](https://leetcode.com/problems/find-pivot-index/)

## range_sum_query
- This problem demonstrates the classic prefix sum approach for efficient range sum queries. The solution precomputes prefix sums in the constructor, allowing each query to be answered in O(1) time. This is an excellent example of space-time tradeoff where we invest O(n) space upfront to achieve O(1) query time. This pattern is fundamental and can be extended to 2D arrays for matrix range sum queries.

[LeetCode Problem: Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)

## subarray_sum_equal_k
- This problem is a sophisticated application of prefix sums combined with hashmap. The key insight is that if we have seen a prefix sum `sum - k` before, then the subarray between those indices sums to `k`. This approach efficiently counts all valid subarrays in O(n) time, which is much better than the O(n²) brute force solution. This technique is fundamental for solving many subarray-related problems and demonstrates the power of combining multiple data structures.

[LeetCode Problem: Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)

## contiguous_array
- This problem demonstrates clever problem transformation and the application of prefix sums with hashmap. By converting 0s to -1, the problem of finding equal numbers of 0s and 1s becomes finding subarrays with sum 0. This is an excellent example of how problem transformation can simplify complex problems. The solution uses the same fundamental technique as subarray sum problems but applies it to a different domain.

[LeetCode Problem: Contiguous Array](https://leetcode.com/problems/contiguous-array/)

## array_concepts_practiced_through_mock_test
- Practiced fundamental array concepts through DSA mock test on 2025-08-15
- Scored 21/30, identifying areas for improvement in understanding of:
  - Data structures used for implementing recursion (should be stack, not just any data structure)
  - Time complexity of traversing a linked list (O(n), not O(log n))
  - Stable sorting algorithms (Quick Sort is not stable)
  - Auxiliary space complexity of merge sort (O(n), not O(log n))
  - Time complexity of building a heap (O(n), not O(log n))
  - Data structures for BFS (queue) and DFS (stack)
  - Circular queue full condition ((rear + 1) % size == front)
- Overall performance shows good understanding of basic DSA concepts with some areas needing refinement

## trapping_rainwater
- The trapping rainwater problem is a classic array manipulation problem that involves calculating how much water can be trapped between bars of different heights after raining.

The key insight is that for each position, the amount of water that can be trapped depends on the minimum of the maximum heights to its left and right. Specifically, water at position i = min(leftMax[i], rightMax[i]) - height[i] (if positive).

Two main approaches are commonly used:

1. **Prefix/Suffix Arrays Approach:** This approach precomputes the maximum height to the left of each position (prefix max) and the maximum height to the right of each position (suffix max). Then, for each position, we calculate the trapped water using the formula above. This approach has O(n) time complexity and O(n) space complexity.

2. **Two-Pointer Approach:** This is a more space-efficient approach that uses two pointers moving from both ends toward the center. It maintains the maximum heights seen so far from both sides and calculates trapped water on the fly. This approach has O(n) time complexity and O(1) space complexity.

The problem demonstrates several important concepts:
- Prefix and suffix computations
- Space-time tradeoffs
- Two-pointer technique
- Problem decomposition (breaking down the problem into smaller, manageable parts)

Applications of this problem pattern include:
- Terrain analysis and flood modeling
- Financial analysis (calculating potential gains/losses)
- Resource allocation problems
- Image processing (histogram-based operations)

[LeetCode Problem: Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

## product_of_array_except_self
- This problem requires calculating the product of all array elements except the current element, without using division. The key insight is that for each position, the result is the product of all elements to its left multiplied by the product of all elements to its right.

The optimal approach uses a two-pass technique:
1. First pass (left to right): Calculate prefix products and store in result array
2. Second pass (right to left): Calculate suffix products and multiply with existing prefix products

This approach achieves O(n) time complexity and O(1) extra space complexity (not counting the output array). The problem demonstrates the power of breaking down a complex calculation into simpler components and using the output array for intermediate storage to optimize space.

[LeetCode Problem: Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

## merge_intervals
- This problem involves merging overlapping intervals in an array. The key insight is to first sort the intervals by their start times, then iterate through them and merge overlapping ones.

The algorithm works as follows:
1. Sort intervals by start time
2. Initialize result with the first interval
3. For each subsequent interval:
   - If it overlaps with the last interval in result (current start ≤ last end), merge them
   - Otherwise, add it as a new interval to the result

This approach has O(n log n) time complexity due to sorting and O(1) extra space complexity. The problem demonstrates the importance of sorting in interval problems and the greedy approach to merging overlapping intervals.

[LeetCode Problem: Merge Intervals](https://leetcode.com/problems/merge-intervals/)

## search_in_rotated_sorted_array
- This problem involves searching for a target in a rotated sorted array. The key insight is that in a rotated sorted array, at any midpoint, at least one half (left or right) is always sorted.

The algorithm uses a modified binary search:
1. At each step, determine which half is sorted
2. Check if the target lies within the sorted half
3. If yes, search in that half; otherwise, search in the other half

This approach maintains O(log n) time complexity and O(1) space complexity. The problem demonstrates how to adapt classic algorithms to handle modified input structures and how to leverage the properties of the data structure to maintain efficiency.

[LeetCode Problem: Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## remove_duplicates_from_sorted_array

- Classic two-pointer problem that efficiently removes duplicates from a sorted array in-place
- Uses a slow pointer to track the position of the last unique element and a fast pointer to scan through the array
- When a new unique element is found (different from the element at the slow pointer), it's placed right after the slow pointer
- The algorithm maintains the relative order of elements while removing duplicates
- Time complexity: O(n) - single pass through the array
- Space complexity: O(1) - modifies the array in-place without using extra space
- This is an optimal solution that's commonly used in systems programming where memory efficiency is important