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

The algorithm starts at the root node and repeatedly compares the target value with the current node's value. Based on the comparison, it either returns the node if the value is found, or it recursively searches the appropriate subtree until the target is found or an empty subtree (resulting in `None`) is reached. This recursive approach efficiently utilizes the BST property of ordered values in each subtree.Approach
========

🤔 What's a Binary Search Tree (BST)?
-------------------------------------

A Binary Search Tree is a special kind of binary tree where:

-   All nodes in the left subtree are smaller than the root.
-   All nodes in the right subtree are larger than the root.

Example:

```
     4
    /\
   2   6
  / \ /\
 1  3 5  7
```

A height-balanced BST means that the depth of the two subtrees of every node never differs by more than 1. This keeps operations like search, insert, and delete efficient (O(log n)).

* * * * *

✨ The Key Idea
--------------

To build a balanced BST from a sorted array, the best approach is:

-   Pick the middle element as the root. This way, the left and right sides of the tree will be roughly balanced.
-   Recursively repeat this process for the left half and the right half of the array.

This strategy guarantees a balanced binary search tree.

* * * * *

🔁 How Recursion Helps
----------------------

Let's say the array is:

```
[1, 2, 3, 4, 5, 6, 7]
```

We can build the tree like this:

1.  Pick `4` (the middle) → it becomes the root.
2.  Recursively build the left subtree with `[1, 2, 3]`
3.  Recursively build the right subtree with `[5, 6, 7]`

This method ensures each subtree is as balanced as possible.

* * * * *

🔍 Visual Example: `nums = [-10, -3, 0, 5, 9]`
----------------------------------------------

Let's walk through how the tree is built step by step from this sorted array.

We want to build a height-balanced binary search tree, so at each step, we select the middle element of the current range to be the root of the (sub)tree.

### 🟩 Step 1: Whole array `[-10, -3, 0, 5, 9]`

-   `left = 0`, `right = 4` → `mid = 2`
-   `nums[2] = 0` becomes the root of the entire tree

```
        0
```

### 🟦 Step 2: Build left subtree with `[-10, -3]`

-   `left = 0`, `right = 1` → `mid = 0`
-   `nums[0] = -10` becomes the left child of 0

```
        0
       /
    -10
```

### 🟧 Step 3: Build right subtree of -10 using `[-3]`

-   `left = 1`, `right = 1` → `mid = 1`
-   `nums[1] = -3` becomes the right child of -10

```
        0
       /
    -10\
      -3
```

### 🟨 Step 4: Build right subtree with `[5, 9]`

-   `left = 3`, `right = 4` → `mid = 3`
-   `nums[3] = 5` becomes the right child of 0

```
        0
       /\
    -10   5\
      -3
```

### 🟪 Step 5: Build right subtree of 5 using `[9]`

-   `left = 4`, `right = 4` → `mid = 4`
-   `nums[4] = 9` becomes the right child of 5

```
        0
       /\
    -10   5
       \\
      -3     9
```

* * * * *

✅ Final Tree Structure
----------------------

```
        0
       /\
    -10   5
       \\
      -3     9
```

-   All elements are placed according to BST rules.
-   The height difference between left and right subtrees at any node is at most 1 → height-balanced.
-   All subtrees themselves are valid BSTs, formed using the same recursive strategy.

* * * * *

📌 Key Concepts Recap
---------------------

-   Choose the middle of the array/subarray as root.
-   Recursively apply the same logic to left and right halves.

* * * * *

✅ Conclusion
------------

This problem is a perfect example of combining:

-   Binary Search Tree rules
-   Divide-and-conquer thinking
-   Recursion

Once you understand this pattern, you'll find it much easier to tackle similar problems involving trees and recursion.


Complexity
==========

-   Time complexity: O(n)

-   Space complexity: O(logn) or O(n)

Code
====

```
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* convert(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = convert(nums, left, mid - 1);
        node->right = convert(nums, mid + 1, right);

        return node;
    }
};
```

* * * * *

Coding Exercise
===============

If you use an original function, how do you write your code?

```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        mid = len(nums) // 2
        root = TreeNode(nums[mid])

        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid+1:])

        return root
```