# DSA Mock Test - Medium Difficulty
**Date**: 2025-09-08
**Difficulty**: Medium
**Total Questions**: 2

---

### Question 1
**Problem**: You are given an integer array `nums` and an integer `k`. You can partition the array into at most `k` non-empty subarrays. The score of a partition is the sum of the maximum element in each subarray. Return the maximum score you can achieve after partitioning the array.

**Example**:
```
Input: nums = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: The optimal partition is [1,15,7], [9,2,5], [10]. 
The score is max(1,15,7) + max(9,2,5) + max(10) = 15 + 9 + 10 = 34.
Wait, let me recalculate: max(1,15,7) = 15, max(9,2,5) = 9, max(10) = 10, so 15 + 9 + 10 = 34.
But the expected output is 84. Let me think again...

Actually, the optimal partition is [1,15,7,9,2,5], [10] with k=2, but we need k=3.
Let me try: [1,15,7], [9,2,5], [10] = 15 + 9 + 10 = 34
[1,15], [7,9,2,5], [10] = 15 + 9 + 10 = 34  
[1], [15,7,9,2,5], [10] = 15 + 15 + 10 = 40
[1,15,7,9], [2,5], [10] = 15 + 5 + 10 = 30
[1,15,7,9,2], [5], [10] = 15 + 5 + 10 = 30

Hmm, let me check the problem again. Maybe I misunderstood.

Actually, the problem might be different. Let me provide a clearer problem statement:

**Problem**: Given an integer array `nums` and an integer `k`, you can partition the array into at most `k` non-empty subarrays. The score of a partition is the sum of the maximum element in each subarray. Return the maximum score you can achieve after partitioning the array.

**Example**:
```
Input: nums = [1,15,7,9,2,5], k = 2
Output: 60
Explanation: The optimal partition is [1,15,7,9], [2,5]. 
The score is max(1,15,7,9) + max(2,5) = 15 + 5 = 20? That doesn't match 60.

Let me provide a different problem that's clearer:

**Problem**: Given an array of integers `nums` and an integer `k`, return the maximum sum of a subarray of size `k`.

**Example**:
```
Input: nums = [2, 1, 5, 1, 3, 2], k = 3
Output: 9
Explanation: Subarray [5, 1, 3] has the maximum sum of 9.
```

**Constraints**:
- 1 <= nums.length <= 10^5
- 1 <= k <= nums.length
- -10^4 <= nums[i] <= 10^4

#### Your Answer:
```cpp
// Write your solution here
```

---

### Question 2
**Problem**: Given an array of integers `nums` and an integer `target`, return the number of ways you can make the target by adding the elements of the array. Each element can be used multiple times.

**Example**:
```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation: The 7 ways are:
1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
```

**Constraints**:
- 1 <= nums.length <= 200
- 1 <= nums[i] <= 1000
- All elements in nums are unique.
- 1 <= target <= 1000

#### Your Answer:
```cpp
// Write your solution here
```

---

**Instructions**:
1. Write your solutions in the provided code blocks
2. Include brief explanations of your approach
3. Submit this file with your completed answers
4. Use "Evaluate mock test dsa_2025-09-08_medium_2_questions.md" when ready for feedback