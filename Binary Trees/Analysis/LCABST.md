Approach
========

This question is not difficult if you understand the binary search tree data structure. In a binary search tree, nodes with values smaller than the parent node are gathered on the left, while nodes with larger values are gathered on the right.

In other words, if both p and q are smaller than the parent, you move to the left. If both p and q are larger than the parent, you move to the right. At some point, if only one of the nodes is larger, that will be the lowest common ancestor.

The conditions can be summarized as follows:

```
if p and q < r → go left
if p and q > r → go right
if p < r < q or p > r > q → r is lowest common ancestor

r is root(parent)
```

Complexity
==========

-   Time complexity: O(h)

-   Space complexity: O(1)

Code
====

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};
```

* * * * *

Bonus
=====

If you want to simplify the codes above.

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (min(p->val, q->val) > root->val) {
                root = root->right;
            } else if (max(p->val, q->val) < root->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};
```