💡 Intuition
============

The problem is to determine whether any root-to-leaf path in the tree has a sum of values equal to a given targetSum.

Our first thought:\
At each step, subtract the current node's value from the remaining sum, and check recursively for both subtrees. If a leaf node has a value equal to the remaining sum, the path is valid.

* * * * *

🛠️ Approach
============

Use Depth-First Search (DFS) to traverse all possible root-to-leaf paths.

At each recursive call:

Subtract the current node's value from the targetSum.

If it's a leaf node, check whether its value equals the remaining target.

Otherwise, continue searching down the left and right subtrees.

Return true if any path satisfies the condition.

* * * * *

⏱️ Complexity
=============

### Time Complexity:

O(n)\
Visit each node once in the worst case.

### Space Complexity:

O(h)\
Recursion stack space where h is the height of the tree.

Code
====

```
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; // ❌ No node to explore

        // ✅ Check for leaf node and match
        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        // 🔁 Recurse with updated target
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
```