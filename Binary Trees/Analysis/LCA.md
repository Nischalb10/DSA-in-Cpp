Approach
========

![スクリーンショット 2025-01-14 1.09.21.png](https://assets.leetcode.com/users/images/b6e72e75-e814-4bb5-80df-fced1197446e_1736784581.666388.png)

```
p = 6, q = 4
```

Since the LCA and target nodes are in a vertical path relationship, I think choosing DFS would be a good option.

```
root 3
left =
right =
```

We move left until node `6`.

```
root 3
left = ---
right =  |
         |
root 5 ←--
left = ---
right =  |
         |
root 6 ←--
left =
right =
```

node `6` is one of target nodes. We traverse all paths under node 6, so let's go back to left of node `5` with node `6`

```
root 3
left = ---
right =  |
         |
root 5 ←--
left = 6
right =
```

We have right path from node `5`. Let's go.

```
root 3
left = ---
right =  |
         |
root 5 ←--
left = 6
right = ---
          |
          |
node 2  ←--
left = ---
right =  |
         |
node 7 ←--
left = ---
right =  |
         |
node null←

Go back to left of node 7 with null and let me skip right.
That is null.

root 3
left = ---
right =  |
         |
root 5 ←--
left = 6
right = ---
          |
          |
node 2  ←--
left = ---
right =  |
         |
node 7 ←--
left = null
right = null

We traversed all paths from node 7.
Let's go back to left of node 2 with null.

root 3
left = ---
right =  |
         |
root 5 ←--
left = 6
right = ---
          |
          |
node 2  ←--
left = null
right = --
         |
node 4 ←--
left =
right =

We found one of the target node.
Let's go back to right of node 2 with node 4.

root 3
left = ---
right =  |
         |
root 5 ←--
left = 6
right = ---
          |
          |
node 2  ←--
left = null
right = 4

We already move all paths under node 2.
Let's go back to right of node 5 with node 4.
```

-   Why we go back to node `5` with node `4`?

Because if we already found both target left and right(= `p` and `q`), current node(node `2`) is LCA. But we don't find them yet, so we return node of left or right if we have one of the nodes. In this case, we return node `4` to node `5`.

```

root 3
left = ---
right =  |
         |
root 5 ←--
left = 6
right = 4

```

Now node `5` is lowest node in the tree and we found `p` and `q`. That means current node `5` is LCA for node `6` and node `4`.

```
return root (= node 5)
```

Complexity
==========

-   Time complexity: O(n)\
    `n` is the number of nodes in the tree.

-   Space complexity: O(h)\
    `h` is the height of the tree.

```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return left != nullptr ? left : right;
    }
};
```