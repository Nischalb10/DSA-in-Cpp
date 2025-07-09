// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

// Example 1:


// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]
// Example 2:


// Input: root = [4,2,7,1,3], val = 5
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [1, 5000].
// 1 <= Node.val <= 107
// root is a binary search tree.
// 1 <= val <= 107
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build BST from level-order input (assumes valid BST input)
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null" || nodes[0] == "-1") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front(); q.pop();

        if (i < nodes.size() && nodes[i] != "null" && nodes[i] != "-1") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null" && nodes[i] != "-1") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Function to search in BST
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    else if (val < root->val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}

// Helper function to print tree level-order from a given node
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "null\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main() {
    cout << "Enter BST in level-order (use 'null' or -1 for empty nodes):\n";
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    vector<string> nodes;
    while (ss >> token) nodes.push_back(token);

    TreeNode* root = buildTree(nodes);

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    TreeNode* result = searchBST(root, val);
    if (result) {
        cout << "Subtree rooted at value " << val << " (level-order): ";
        printLevelOrder(result);
    } else {
        cout << "Value not found in BST.\n";
    }

    return 0;
}
