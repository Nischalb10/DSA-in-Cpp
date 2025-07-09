// Given the root of a binary tree, invert the tree, and return its root.

 

// Example 1:


// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// Example 2:


// Input: root = [2,1,3]
// Output: [2,3,1]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build tree from level-order input
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

// Function to print tree level-order
void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "Tree is empty.\n";
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

// Function to invert binary tree
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

int main() {
    cout << "Enter tree nodes in level-order (use 'null' or -1 for empty nodes):\n";
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    vector<string> nodes;
    while (ss >> token) nodes.push_back(token);

    TreeNode* root = buildTree(nodes);

    cout << "Original tree (level-order): ";
    printLevelOrder(root);

    TreeNode* inverted = invertTree(root);

    cout << "Inverted tree (level-order): ";
    printLevelOrder(inverted);

    return 0;
}
