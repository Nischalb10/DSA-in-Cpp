// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
// Example 2:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
// Example 3:

// Input: root = [1,2], p = 1, q = 2
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [2, 105].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the tree.
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build binary tree from level-order input and map values to TreeNode pointers
TreeNode* buildTree(const vector<string>& nodes, unordered_map<int, TreeNode*>& nodeMap) {
    if (nodes.empty() || nodes[0] == "null" || nodes[0] == "-1") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    nodeMap[root->val] = root;
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front(); q.pop();

        if (i < nodes.size() && nodes[i] != "null" && nodes[i] != "-1") {
            TreeNode* left = new TreeNode(stoi(nodes[i]));
            curr->left = left;
            nodeMap[left->val] = left;
            q.push(left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null" && nodes[i] != "-1") {
            TreeNode* right = new TreeNode(stoi(nodes[i]));
            curr->right = right;
            nodeMap[right->val] = right;
            q.push(right);
        }
        i++;
    }

    return root;
}

// Lowest Common Ancestor function (recursive)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr) {
        return root;
    }

    return left != nullptr ? left : right;
}

int main() {
    cout << "Enter tree nodes in level-order (use 'null' or -1 for empty):\n";
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    vector<string> nodes;
    while (ss >> token) nodes.push_back(token);

    unordered_map<int, TreeNode*> nodeMap;
    TreeNode* root = buildTree(nodes, nodeMap);

    int pVal, qVal;
    cout << "Enter value of node p: ";
    cin >> pVal;
    cout << "Enter value of node q: ";
    cin >> qVal;

    if (nodeMap.count(pVal) == 0 || nodeMap.count(qVal) == 0) {
        cout << "One or both nodes not found in the tree.\n";
        return 1;
    }

    TreeNode* lca = lowestCommonAncestor(root, nodeMap[pVal], nodeMap[qVal]);
    if (lca)
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found.\n";

    return 0;
}
