💡 Intuition
============

Think of a mirror. Inverting a binary tree is just like placing a mirror in front of it:\
You need to flip each node's left and right children recursively.

* * * * *

🛠️ Approach
============

Use post-order traversal (left → right → root) to visit each node.

At every node:

Recursively invert its left subtree.

Recursively invert its right subtree.

Swap the left and right children.

Return the root of the inverted tree.

This is naturally a recursive problem due to its tree structure.

* * * * *

⏱️ Complexity
=============

### Time Complexity:

O(n)\
We visit each of the n nodes once.

### Space Complexity:

O(h)\
Due to recursion call stack, where h is the height of the tree (worst case:\
O(n) for skewed, best:\
O(logn) balanced).

Code
====

```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr; // 🔚 Base case

        // 🔁 Invert left and right recursively
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        // 🔄 Swap children
        root->left = right;
        root->right = left;

        return root; // ✅ Return the modified root
    }
};
```