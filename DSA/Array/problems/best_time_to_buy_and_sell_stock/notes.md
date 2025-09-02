# Best Time to Buy and Sell Stock

## Problem Statement
You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## Approach
This solution uses a single pass approach to track the minimum price seen so far and calculate the maximum profit that could be achieved at each day.

## Solution Explanation
1. Initialize minPrice to the price on the first day and maxProfit to 0
2. Iterate through the prices array starting from the second day:
   - If the current price is less than minPrice, update minPrice
   - Calculate the profit that could be achieved by selling on the current day (current price - minPrice)
   - Update maxProfit if this profit is greater than the current maxProfit
3. Return maxProfit

## Time Complexity
O(n) - We traverse the array once

## Space Complexity
O(1) - We use only constant extra space