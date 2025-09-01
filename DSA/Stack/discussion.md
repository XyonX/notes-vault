# Stack

This folder contains problems related to Stack data structure.

## parenthesis_checker
- This problem tests understanding of stack operations and matching pairs.
- The key insight is that for every closing bracket, there must be a corresponding opening bracket of the same type that was most recently encountered (LIFO principle).
- Edge cases to consider: empty string, unmatched brackets, incorrect ordering.

## next_greater_element
- This problem demonstrates the monotonic stack pattern, where we maintain a stack with elements in a specific order.
- Processing the array from right to left allows us to efficiently compute the next greater element for each position.
- The stack maintains potential candidates for "next greater elements" in decreasing order.

## asteroid_collision
- This problem combines stack operations with complex conditional logic.
- The stack represents asteroids that are currently "alive" and moving right.
- When a left-moving asteroid is encountered, we simulate collisions with right-moving asteroids in the stack.
- Multiple collision scenarios must be handled: same size (both explode), larger right-moving (left explodes), larger left-moving (right explodes).