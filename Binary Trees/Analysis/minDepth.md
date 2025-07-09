### Intuition

To find the minimum depth of a binary tree, we can leverage BFS to ensure we hit the first leaf node as early as possible. BFS is optimal for this task because it explores level by level.

* * * * *

### Approach

![image.png](https://assets.leetcode.com/users/images/3701c5cc-d4d9-4586-b57e-27714a79f5ee_1743832799.3841598.png)

Use a queue to perform a level-order traversal. Track the depth as we go, and the moment we encounter the first leaf node (a node without children), return the current depth. This guarantees the shortest path from root to leaf.

* * * * *

### Complexity

Time Complexity:

-   ( O(n) ), where `n` is the number of nodes --- in the worst case, every node may be visited.

Space Complexity:

-   ( O(n) ), for queue space in the worst case (skewed tree).