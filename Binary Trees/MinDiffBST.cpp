// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

// Example 1:


// Input: root = [4,2,6,1,3]
// Output: 1
// Example 2:


// Input: root = [1,0,48,null,null,12,49]
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [2, 104].
// 0 <= Node.val <= 105
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int prev;
    int ans;
public:
    int getMinimumDifference(TreeNode* root) {
        prev = -1;
        ans = INT_MAX;
        dfs(root);
        return ans;
    }

private:
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        if (prev != -1) {
            ans = min(ans, node->val - prev);
        }
        prev = node->val;
        dfs(node->right);
    }
};

// Helper to delete tree and avoid leaks
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    /*
        Construct the BST:
              4
             / \
            2   6
           / \
          1   3
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int result = sol.getMinimumDifference(root);

    cout << "Minimum absolute difference: " << result << endl;

    deleteTree(root); // Free memory
    return 0;
}
