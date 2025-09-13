## check_anagrams
- logic was quite easy
- what i have learned how to use array as map for string
- how to work wiht string asccii and the 'a' subtraction

## check_palindrome
- the basic code of palindrome
- i did impkemented first whihc was wrokign for the ony same caps
- later i have learned to use trhe tolower to make it work for any case
- i later implemented the recursivce code to practicve my recursion skill
- Added implementations for checking palindromes in arrays (both iterative and recursive)
- Added alternative implementation for string palindrome checking

## first_non_repeating_character
- its anotehr code to get the first char non repeating char

## counting_valleys
- Problem involves tracking altitude changes during a hike
- A valley is defined as a sequence of steps below sea level, starting with a 'D' and ending with a 'U'
- Solution approach:
  - Track current altitude (0 = sea level)
  - For each step:
    - 'U' increases altitude
    - 'D' decreases altitude
  - Only increment valley count when returning to sea level (altitude = 0) after being below it
- Time complexity: O(n) where n is the number of steps
- Space complexity: O(1) - only using a few variables

## string_to_integer_atoi
- Implementation of the classic ATOI function to convert strings to integers
- Iterative approach that processes the string character by character
- Key considerations:
  - Handling leading whitespace
  - Determining the sign of the number (+ or -)
  - Converting valid digit characters to numeric values
  - Stopping conversion when a non-digit character is encountered
- This is a common interview problem that tests string manipulation and edge case handling

## valid_anagram
- Efficient solution using frequency counting with a fixed-size array
- Key insight: Anagrams must have identical character counts
- Handles case insensitivity by converting characters to lowercase
- Input validation ensures only alphabetic characters are processed
- Time complexity: O(n) where n is the length of the strings
- Space complexity: O(1) since the array size is fixed (26 elements)

## group_anagrams
- Elegant solution using sorted strings as hash map keys
- All anagrams will have the same sorted representation
- Time complexity: O(n * k log k) where n is number of strings and k is maximum string length
- Space complexity: O(n * k) to store all strings in the hash map
- The solution demonstrates effective use of sorting and hash maps for grouping

## longest_common_subsequence
- Classic dynamic programming problem with two approaches:
  1. Recursive without memoization: Exponential time complexity
  2. DP with memoization: Polynomial time complexity O(m*n)
- Enhanced with better parameter naming and comments for clarity
- The DP approach uses a 2D table to store intermediate results
- Key insight: overlapping subproblems can be solved once and reused
- Comprehensive test cases validate the solution across various scenarios

## longest_palindromic_subsequence
- Two implementations provided, both needing optimization:
  1. Backtracking approach: Tracks actual palindrome strings, exponential time
  2. Recursive approach: Only tracks length, still exponential
- Helper function `isPalindrome` efficiently checks if a string is a palindrome
- The problem requires a DP solution for optimal performance
- Current implementations serve as learning exercises but need optimization for large inputs

## longest_substring_without_repeating_characters
- Classic sliding window problem that efficiently finds the longest substring with unique characters
- Uses two pointers (left and right) to maintain a dynamic window
- Employs a frequency array to track the last seen index of each character
- Key insight: When a repeated character is found, move the left pointer to maintain uniqueness
- Time complexity: O(n) where n is the length of the string
- Space complexity: O(1) using a fixed-size array for character frequencies
- This is an optimal solution that demonstrates the sliding window technique effectively

## longest_common_substring
- String matching problem that finds the longest contiguous sequence of characters common to two strings
- Two recursive implementations provided, both with exponential time complexity
- First approach builds the substring during recursion and requires a final reversal
- Second approach compares substring lengths and returns the longer one when characters don't match
- Both implementations explore all possible paths, making them inefficient for large inputs
- This problem demonstrates the difference between substring (contiguous) and subsequence (not necessarily contiguous)
- A dynamic programming solution would be more efficient with O(m*n) time complexity
- The problem is a good example of how recursion can lead to exponential time complexity and why optimization techniques like memoization or DP are needed

## longest_palindromic_substring
Expand Around Center is a classic approach for palindrome problems. For each possible center (character for odd, between characters for even), expand while characters match. Track the longest found. This beats Manacher's algorithm in simplicity for interviews, though O(n²) is acceptable for n≤1000. Common pitfalls: forgetting even-length cases, off-by-one in bounds. LeetCode #5 often pairs with Longest Palindromic Subsequence (#516) to contrast contiguous vs non-contiguous.
