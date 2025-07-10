// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.
 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

// Example 2:

// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.
// Example 3:

// Input: root = [], key = 0
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -105 <= Node.val <= 105
// Each node has a unique value.
// root is a valid binary search tree.
// -105 <= key <= 105
 

// Follow up: Could you solve it with time complexity O(height of tree)?
#include <iostream>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    TreeNode* inPre(TreeNode* p) {
        while (p && p->right != nullptr)
            p = p->right;
        return p;
    }

    TreeNode* inSucc(TreeNode* p) {
        while (p && p->left != nullptr)
            p = p->left;
        return p;
    }

    TreeNode* deleteNode(TreeNode* p, int key) {
        if (p == nullptr) return nullptr;

        if (key < p->val) {
            p->left = deleteNode(p->left, key);
        } else if (key > p->val) {
            p->right = deleteNode(p->right, key);
        } else {
            // Node found
            if (!p->left && !p->right) {
                delete p;
                return nullptr;
            } else if (!p->left) {
                TreeNode* temp = p->right;
                delete p;
                return temp;
            } else if (!p->right) {
                TreeNode* temp = p->left;
                delete p;
                return temp;
            } else {
                if (height(p->left) > height(p->right)) {
                    TreeNode* q = inPre(p->left);
                    p->val = q->val;
                    p->left = deleteNode(p->left, q->val);
                } else {
                    TreeNode* q = inSucc(p->right);
                    p->val = q->val;
                    p->right = deleteNode(p->right, q->val);
                }
            }
        }

        return p;
    }
};

// Helper function to print in-order traversal
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    // Create BST: [5,3,6,2,4,null,7]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << "Original BST (in-order): ";
    printInOrder(root);
    cout << "\n";

    // Delete node with two children (3)
    root = sol.deleteNode(root, 3);
    cout << "After deleting 3: ";
    printInOrder(root);
    cout << "\n";

    // Delete node with one child (6)
    root = sol.deleteNode(root, 6);
    cout << "After deleting 6: ";
    printInOrder(root);
    cout << "\n";

    // Delete leaf node (2)
    root = sol.deleteNode(root, 2);
    cout << "After deleting 2: ";
    printInOrder(root);
    cout << "\n";

    return 0;
}
