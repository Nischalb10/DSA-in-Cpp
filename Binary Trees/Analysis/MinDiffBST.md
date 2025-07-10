Intuition
=========

In a Binary Search Tree, the in-order traversal gives nodes in sorted order. So, the minimum absolute difference will always be between two adjacent nodes in this sequence.

Approach
========

![image.png](https://assets.leetcode.com/users/images/b5d4e222-226a-4014-9292-160e778067cd_1745210847.0741248.png)

1.  Perform in-order traversal.
2.  At each node, calculate the difference between current and previous node.
3.  Keep track of the smallest difference found.

Complexity
==========

-   Time complexity:\
    O(n) --- We visit each node once.

-   Space complexity:\
    O(h) --- Recursion stack where h is the height of the tree.