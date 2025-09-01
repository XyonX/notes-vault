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