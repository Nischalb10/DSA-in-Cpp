Intuition
=========

To print the tree level by level, a breadth-first search (BFS) approach is perfect because it processes all nodes at the current depth before moving to the next.

Approach
========

I used a queue to traverse the tree in BFS order. For each level, I collect the node values in a temporary vector, then add it to the answer. Push left and right children into the queue for the next level.

Complexity
==========

-   Time complexity:\
    Time complexity: O(n) (visit every node once)

-   Space complexity:\
    Space complexity: O(n) (queue and result storage)

Code
====

```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> level;
            for(int i = 0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
```