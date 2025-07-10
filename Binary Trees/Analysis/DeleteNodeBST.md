When we delete a node from a Binary Search Tree(BST), the BST properties should remain the same.\
Hence, we have 3 cases for deleting a node from a BST :

1.  *The node is a leaf node* - In this cases, we can just delete the node and return the root, since deleting any elaf node doesn't affect the remainig tree.\
    ![image](https://assets.leetcode.com/users/images/e3c9bd80-7b8d-40c5-9d44-2eec84772544_1637543079.1645782.png)

2.  *The node has one child* - In this case, replace the node with the child node and return the root.\
    ![image](https://assets.leetcode.com/users/images/82448a74-6e63-4981-bd93-68915b47536d_1637542697.778318.png)

3.  *The node has 2 children* - In this case, in order to conserve the BST properties, we need to replace the node with it's inorder successor (The next node that comes in the inorder traversal) i.e; we need to replace it with either :\
    1\. The greatest value node in it's left subtree (or)\
    2\. The smallest value node in it's right subtree\
    and return the root.\
    ![image](https://assets.leetcode.com/users/images/03774f6e-5bf0-4805-8fc0-b810b636386e_1637542708.968784.png)

Time Complexity : O(h) - h = height of the tree.\
(Worst case Time Complexity : O(n) )

Code :

```
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root)
            if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
            else if(key > root->val) root->right = deleteNode(root->right, key);
            else{
                if(!root->left && !root->right) return NULL;          //No child condition
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
					                                                //Two child condition
                TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
                while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
            }
        return root;
    }
};
```