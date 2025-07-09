#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

// Tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree from level-order input
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

// Find minimum value using BFS
int findMin(TreeNode* root) {
    if (!root) return INT_MAX;
    int minVal = INT_MAX;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        minVal = min(minVal, node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return minVal;
}

// Find maximum value using BFS
int findMax(TreeNode* root) {
    if (!root) return INT_MIN;
    int maxVal = INT_MIN;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        maxVal = max(maxVal, node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return maxVal;
}

int main() {
    cout << "Enter tree nodes in level-order (use 'null' or -1 for null):\n";
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    vector<string> nodes;
    while (ss >> token) {
        nodes.push_back(token);
    }

    TreeNode* root = buildTree(nodes);
    int minValue = findMin(root);
    int maxValue = findMax(root);

    cout << "Minimum Value: " << minValue << endl;
    cout << "Maximum Value: " << maxValue << endl;

    return 0;
}
