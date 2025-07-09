// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

// Example 1:


// Input: p = [1,2,3], q = [1,2,3]
// Output: true
// Example 2:


// Input: p = [1,2], q = [1,null,2]
// Output: false
// Example 3:


// Input: p = [1,2,1], q = [1,1,2]
// Output: false
 

// Constraints:

// The number of nodes in both trees is in the range [0, 100].
// -104 <= Node.val <= 104
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// Tree node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build binary tree from level-order input
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

// Check if two binary trees are the same
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p || !q) return p == q;
    return (p->val == q->val) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {
    cout << "Enter first tree nodes in level-order (use 'null' or -1 for nulls):\n";
    string line1;
    getline(cin, line1);
    stringstream ss1(line1);
    string token1;
    vector<string> nodes1;
    while (ss1 >> token1) {
        nodes1.push_back(token1);
    }

    cout << "Enter second tree nodes in level-order (use 'null' or -1 for nulls):\n";
    string line2;
    getline(cin, line2);
    stringstream ss2(line2);
    string token2;
    vector<string> nodes2;
    while (ss2 >> token2) {
        nodes2.push_back(token2);
    }

    TreeNode* tree1 = buildTree(nodes1);
    TreeNode* tree2 = buildTree(nodes2);

    bool result = isSameTree(tree1, tree2);
    cout << (result ? "Trees are the same." : "Trees are different.") << endl;

    return 0;
}
