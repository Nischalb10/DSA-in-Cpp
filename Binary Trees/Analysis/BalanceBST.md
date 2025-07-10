💡 # Intuition
==============

An unbalanced BST may degrade to a linked list-like structure, causing inefficient operations.\
But if we extract the elements in sorted order (inorder traversal), we can rebuild a perfectly height-balanced BST.

* * * * *

🛠️ # Approach
==============

Inorder Traversal:

Traverse the BST in inorder (Left ➝ Root ➝ Right) to get a sorted array of node values.

Rebuild Tree:
=============

Use divide & conquer to construct a balanced BST from the sorted array.

Choose the middle element as the root to ensure balance.

Recursively build left and right subtrees from the left and right halves of the array.

* * * * *

⏱️ # Complexity
===============

### Time Complexity:

O(n)

#### Inorder traversal:

O(n)

### Building balanced BST:

O(n)

#### Space Complexity:

O(n)

### Sorted list of node values:

O(n)

### Recursion stack:

O(logn) in balanced case

Code
====

```
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
    vector<int> nodes;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);              // ⬅️ Left
        nodes.push_back(root->val);       // ⬆️ Root
        inorder(root->right);             // ➡️ Right
    }

    TreeNode* build(int start, int end) {
        if (start > end) return nullptr;  // 🧱 Base case

        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);     // ⬆️ Mid becomes root
        node->left = build(start, mid - 1);             // ⬅️ Left subtree
        node->right = build(mid + 1, end);              // ➡️ Right subtree
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);                         // 📥 Convert to sorted list
        return build(0, nodes.size() - 1);     // 🔁 Build balanced BST
    }
};
```