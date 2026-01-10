# reverse_words

## Solution
Trim leading/trailing spaces, reverse entire string, append space, reverse each word segment (between spaces), remove trailing space.

## Notes
- Time: O(n), Space: O(1) in-place reverses.
- Handles multiple/leading/trailing spaces, single word, empty (after trim: empty string).
- Tests: Basic ('the sky is blue' -> 'blue is sky the'), spaces ('  hello world  ' -> 'world hello'), multiple ('a good   example' -> 'example good a'), single ('hello' -> 'hello'), extra spaces - all pass.
- Solves LeetCode 151.

## LeetCode Link
[Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) (Medium)

Status: solved
