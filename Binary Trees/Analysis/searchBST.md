* * * * *

Approach
========

Typical Binary Search Tree has rules as follow:

* * * * *

⭐️ Points

-   All values of left side of current root are less than the root value.
-   All values of right side of current root are greater than the root value.

* * * * *

Let's solve this qustion with the example below.

```
       7
     /\
    5    10
   / \   /\
  2   6 8  15
            /\
           12 20

val = 15
```

We are now at `7`.We have two choices. Go left or right with the rule above.

In this case, we should go right because

```
15 > 7
```

Now we are at 10. Again we have two choices.

```
15 > 10
```

Now we find the same value, so return current node.

Easy!😃\
Let's see solution codes!


Complexity
==========

-   Time complexity:

    -   In the worst case, the height (h) could be as large as (n)(the number of nodes) if the tree is unbalanced, leading to O(n)complexity.
    -   In the best case, if the tree is balanced, the height (h) would be (logn), leading to O(logn) complexity.
-   Space complexity:

    -   In the worst case, the space complexity is O(n) if the tree is completely unbalanced.
    -   In the best case, the space complexity is O(logn) if the tree is balanced.

```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return nullptr;
        }
        if (root->val == val) {
            return root;
        } else if (root->val > val) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    }
};
```

1\. Base Case:

-   If the `root` node is `None`, the search is complete, and the target value is not found. Return `None`.

2\. Search for Value:

-   Compare the target value (`val`) with the current node's value (`root.val`).
-   If `val == root.val`, the search is successful. Return `root` as the node containing the target value.

3\. Recursive Search (Left or Right Subtree):

-   If `val < root.val`:
    -   The target value is smaller than the current node, so it must be in the left subtree (remember BST property).
    -   Recursively call the same logic (steps 2-4) on the `root.left` subtree, passing the same `val` to search for.
-   If `val > root.val`:
    -   The target value is larger than the current node, so it must be in the right subtree (remember BST property).
    -   Recursively call the same logic (steps 2-4) on the `root.right` subtree, passing the same `val` to search for.

4\. Recursive Result Handling:

-   The result of the recursive call (either `None` if not found or the node containing the value) is returned by the current step.

Overall Process:

The algorithm starts at the root node and repeatedly compares the target value with the current node's value. Based on the comparison, it either returns the node if the value is found, or it recursively searches the appropriate subtree until the target is found or an empty subtree (resulting in `None`) is reached. This recursive approach efficiently utilizes the BST property of ordered values in each subtree.