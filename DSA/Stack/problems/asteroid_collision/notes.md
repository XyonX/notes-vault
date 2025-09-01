# Asteroid Collision

## Problem Statement
We are given an array asteroids of integers representing asteroids in a row. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed. Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

## Approach
This solution uses a stack to simulate the collisions:
1. Iterate through the asteroids array
2. For each asteroid:
   - If it's moving right (positive), push it onto the stack
   - If it's moving left (negative):
     * While there are right-moving asteroids in the stack that are smaller than the current asteroid, pop them (they explode)
     * If the top of the stack is the same size as the current asteroid, both explode (pop and don't add current)
     * If the top of the stack is larger than the current asteroid, the current asteroid explodes (don't add it)
     * If the stack is empty or contains only left-moving asteroids, add the current asteroid

## Time Complexity
O(n) where n is the number of asteroids. Each asteroid is pushed and popped from the stack at most once.

## Space Complexity
O(n) for the stack.

## Key Points
- This problem demonstrates a more complex application of the stack data structure
- The collision logic requires careful handling of multiple cases
- The stack maintains asteroids that have survived collisions so far
- Negative asteroids (moving left) can only collide with positive asteroids (moving right) that came before them

## LeetCode Link
[Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)