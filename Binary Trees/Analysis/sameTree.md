Approach
========

If we find a false case, we should return false, so let's focus on true cases.

I think we have two true cases.

* * * * *

⭐️ Points

1.  both values at the same place are the same
2.  both values at the same place are null

* * * * *

I believe the point 1 is easy to understand right? The point 2 is a case where we reach end of tree which is the next node of leaf nodes. In the example below, under `node 2` and `node 3`

![スクリーンショット 2024-02-26 10.08.23.png](https://assets.leetcode.com/users/images/f98f9f43-5ac8-4a18-9ad3-5747902c6f48_1708916481.701511.png)

If we find true cases, we move to the next node, if not, we should return false immediately.

Easy!😄\
Let's see solution codes and step by step algorithm!


Complexity
==========

-   Time complexity: O(n)\
    `n` is the total number of nodes in the binary trees.

-   Space complexity: O(h) orO(n)\
    `h` is height of deeper tree. That is average. In the worst case, O(n) because of skewed tree.

```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        return false;
    }
};
```

Step by step algorithm
----------------------

1.  Check if both trees are empty (both p and q are None):

```
if not p and not q:
    return True
```

This condition checks if both `p` and `q` are `None`, indicating that both trees are empty. If this condition is met, it returns `True`, indicating that the trees are the same.

1.  Check if both trees are non-empty and have the same root value:

```
if p and q and p.val == q.val:
    return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```

If both `p` and `q` are non-empty and have the same root value, we recursively call the `isSameTree` function on their left and right subtrees. This recursive call checks if the left subtrees of `p` and `q` are the same and if the right subtrees of `p` and `q` are the same. If all these conditions are met, it returns `True`, indicating that the trees are the same.

1.  Return False if none of the above conditions are met:

```
return False
```

If none of the above conditions are met, it means that the trees are not the same, so it returns `False`.

This algorithm efficiently determines if two binary trees are the same by recursively comparing their structures and node values.

* * * * *

Bonus
=====

Can you modify the solution codes? Here is another way to solve the question.

```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return p == q;
        }

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

I changed the first condition.

from

```
if not p and not q:
```

to

```
if not p or not q:
```

If we use `or`, we have to check if both nodes are `null or not`. And if both nodes are `null`, we should return `true`, if not, return `false`.

The reason why we check `null` again is that if `p` is `null`, `not p` is `true`, so we don't know `q` is not null yet.

If we don't meet the first condition above, that means both nodes are not `null`, so just compare both values and go to `left` and `right`.