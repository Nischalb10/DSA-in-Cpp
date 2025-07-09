### 💡 Intuition

We are asked to compute the average value of nodes on each level of a binary tree.\
This is a straightforward level order traversal (BFS) problem.\
We process each level, accumulate the sum of node values, and divide by the number of nodes at that level.

* * * * *

### 🛠️ Approach

-   Use a queue to perform BFS.
-   For each level:
    -   Track the number of nodes.
    -   Add all node values at that level.
    -   Compute the average and store it.
-   Repeat this for all levels.

* * * * *

### ⏱️ Complexity

-   Time Complexity: O(n)
-   Space Complexity: O(n)

### ✅ Code

```
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            double sum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(sum / size);
        }

        return res;
    }
};
```