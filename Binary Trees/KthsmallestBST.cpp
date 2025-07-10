// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

// Example 1:


// Input: root = [3,1,4,null,2], k = 1
// Output: 1
// Example 2:


// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
 

// Constraints:

// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
 

// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
#include <iostream>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void preorder(TreeNode* root, int k , int &count , int &ans){
        if(!root) return;
        preorder(root->left,k,count,ans);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        preorder(root->right,k,count,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        preorder(root,k,count,ans);
        return ans;
    }
};

int main() {
    // Create BST
    /*
            5
           / \
          3   6
         / \
        2   4
       /
      1
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution sol;

    for (int k = 1; k <= 6; ++k) {
        cout << "The " << k << "-th smallest element is: " << sol.kthSmallest(root, k) << endl;
    }

    // Optional: cleanup (not mandatory in small examples)
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
