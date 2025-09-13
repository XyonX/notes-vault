## tree_traversals
- Notes: Preorder, Inorder, Postorder traversal implementations on a perfect binary tree (1..7). Prints nodes without separators; complexity O(n).

## binary_search_tree
- Notes: Implementation of a Binary Search Tree with insert and in-order traversal methods. Time complexity for search/insert is O(log n) on average.

## level_order_traversal
- Notes: Implementation of level order traversal (BFS) for a binary tree using a queue. Time complexity O(n), space complexity O(w) where w is maximum width.

## bst_deletion
- Notes: Implementation of deletion in a Binary Search Tree. Handles three cases: leaf node, node with one child, and node with two children (using inorder successor). Time complexity O(log n) average, O(n) worst case.

## diameter_of_binary_tree
- Notes: Calculates the diameter of a binary tree (longest path between any two nodes) using a height function. Time complexity O(n), space complexity O(h).

## lowest_common_ancestor
- Notes: Finds the lowest common ancestor of two nodes in a binary tree using recursion. Time complexity O(n), space complexity O(h).

## validate_bst
- Notes: Validates if a binary tree is a valid binary search tree by checking node values against a valid range. Time complexity O(n), space complexity O(h).

## tree_array_representation
- **Approach**: Array storage for complete binary tree (level order). Index formulas for parent/children. Iterative preorder using stack (push right then left).
- **Time**: O(1) access, O(n) traversal
- **Space**: O(n) array + O(h) stack
- **Key**: Space-efficient vs pointer trees; useful for heaps.

## tree_inorder_iterative
- **Approach**: Stack-based inorder (LNR). Nullify left after pushing to avoid loops; print when no left remains, then push right.
- **Time**: O(n)
- **Space**: O(h)
- **Key**: Modifies tree temporarily; alternative to recursion for deep trees.
