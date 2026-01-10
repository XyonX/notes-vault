## sample_data_insertion
- SQL BAISC NOTES -- insert sample

## inner_join_example
- BASIC CODE WE WROTE THAT USED THE INNER JOIN
WE GET TO KNOW THE BASIC JOIIN SYNTAX

## aggregate_function_count
- IN THIS EXAMPLE WE SAW TRHE SE OF AGGREATE FUCNTION COUNT

## group_by_with_having
- -WE USED GROUP BY TO GET TGE TOTAL AMOUNT SPEND BY A USER

## order_by_with_limit
- --THE USE OF ORDER BY WIHT LIMIT TO GETTH MOST 2 EXPENSIVE PRODUCT

## case_statement
- No notes provided.

## station_schema
- ## STATION SCHEMA FROM HACKER RANK

## cities_starting_with_vowels
- --WE USED DISTINCT TO SHOW UNQIUE RESULT AND REG EX FOR REGURALR EX ^ IS USED TO MENMTNIN STATIRING AND [] ANYTHIGN INSIDE IT WILL WORK ANY OF THEM

## cities_ending_with_vowels
- --WE SW HOW TO USE REGULAR EXPRESSION TO MATCH ANY CHAR AT THE END

## cities_starting_and_ending_with_vowels
- --I GET TO KNOW HOW TO USE THE .* TO have any chanracter in between

## cities_not_starting_with_vowels
- --^ outside brackets = beginning of string

--[^AEIOUaeiou] = any character except a vowel

## cities_not_ending_with_vowels
- What it does:

--Picks city names ending with non-vowel characters

--The [^AEIOUaeiou] part means "anything except a vowel"

--Anchored with $, so it matches only the final character

--DISTINCT ensures no duplicates

## second_highest_salary
- This problem demonstrates multiple approaches to find the second highest salary:
  1. Using LIMIT and OFFSET
  2. Using a subquery with MAX
  3. Using ROW_NUMBER() window function
  4. Using DENSE_RANK() window function for handling duplicates

- Each approach has its own advantages and considerations for edge cases.
