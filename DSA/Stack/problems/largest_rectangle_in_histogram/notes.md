# Largest Rectangle in Histogram

## Problem Statement
Given an array of integers `heights` representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

## Approach
This solution uses the concept of finding the next smaller element (NSE) and previous smaller element (PSE) for each bar in the histogram. For each bar, the maximum rectangle that can be formed with that bar as the smallest one will have:
- Left boundary: PSE index + 1
- Right boundary: NSE index - 1
- Width: NSE index - PSE index - 1
- Area: height[i] * width

## Solution Explanation
1. Calculate the next smaller element for each bar
2. Calculate the previous smaller element for each bar
3. For each bar, calculate the maximum rectangle area using the formula: `height[i] * (nextSmaller - prevSmaller - 1)`
4. Return the maximum area found

## Time Complexity
O(n) - We traverse the array a constant number of times

## Space Complexity
O(n) - For the stack and result arrays