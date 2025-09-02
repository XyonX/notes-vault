## check_anagrams
- Notes: 
- logic was quite easy
- what i have learned how to use array as map for string
- how to work wiht string asccii and the 'a' subtraction

## check_palindrome
- Notes:
- the basic code of palindrome
- i did impkemented first whihc was wrokign for the ony same caps
- later i have learned to use trhe tolower to make it work for any case
- i later implemented the recursivce code to practicve my recursion skill
- Added implementations for checking palindromes in arrays (both iterative and recursive)
- Added alternative implementation for string palindrome checking

## first_non_repeating_character
- Notes:
- its anotehr code to get the first char non repeating char

## counting_valleys
- Notes:
- Count valleys in a hiking path using altitude tracking
- Increment valley count only when returning to sea level from below
- Uses simple iteration with altitude counter

## string_to_integer_atoi
- Notes:
- Implementation of custom atoi function to convert string to integer
- Includes iterative approach
- Handles whitespace, signs, and digit conversion

## valid_anagram
- Notes:
- Efficient anagram checking using frequency array
- Handles case insensitivity with tolower
- Validates input to ensure only alphabetic characters
- Time Complexity: O(n), Space Complexity: O(1)

## group_anagrams
- Notes:
- Groups anagrams using sorted string signatures as keys
- Uses hash map for efficient grouping
- Time Complexity: O(n * k log k), Space Complexity: O(n * k)
- Includes helper function for displaying grouped results

## longest_common_subsequence
- Notes:
- Dynamic programming solution with memoization
- Two approaches: recursive (inefficient) and DP (optimal)
- Enhanced with better parameter naming and comments
- Time Complexity: O(m*n), Space Complexity: O(m*n)
- Comprehensive test cases covering various scenarios

## longest_palindromic_subsequence
- Notes:
- Two implementations: backtracking (inefficient) and recursive (still needs optimization)
- Helper function for palindrome checking
- Notes that DP solution is needed for optimal performance
- Current implementations exceed time limits for large inputs

## longest_substring_without_repeating_characters
- Notes:
- Sliding window technique with frequency array to track last seen index of characters
- Uses two pointers to maintain current window
- Time Complexity: O(n), Space Complexity: O(1)

## longest_common_substring
- Notes:
- Two recursive implementations for finding longest common substring
- First approach builds substring during recursion and requires reversal
- Second approach returns longer of two possible substrings when characters don't match
- Both have exponential time complexity O(2^(m+n))
- Known Issues: Inefficient for large inputs; DP solution would be better