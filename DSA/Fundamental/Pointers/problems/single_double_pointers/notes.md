# Single and Double Pointers in C++

## Problem Description
This code demonstrates the difference between using single pointers and double pointers in C++ when trying to update objects. It shows two approaches to object creation and modification through pointers.

## Code Explanation
The implementation includes:
1. A `demo` class with a data member and a display function
2. `create()` function: Uses a single pointer to modify the object it points to
3. `create_2()` function: Uses a double pointer to update the pointer itself
4. `main()` function: Demonstrates both approaches

## Key Concepts
- **Single Pointer Approach**: Modifies the content of the object that the pointer points to, but cannot change the address stored in the pointer itself
- **Double Pointer Approach**: Can modify both the content of the object and the address stored in the original pointer

## Important Notes
- The single pointer approach modifies the object in place but doesn't update the pointer to point to a new object
- The double pointer approach can update the original pointer to point to a completely new object
- The single pointer approach shown in the code has memory management issues (potential memory leak)

## Known Issues
- The code contains several spelling errors and typos in comments
- The single pointer approach in `create()` function has a memory leak as the `obj` allocated with `new` is not deleted
- The code doesn't follow best practices for memory management in C++