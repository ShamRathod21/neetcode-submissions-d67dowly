/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        queue<TreeNode*> treeQ;
        treeQ.push(root);
        while(!treeQ.empty()) {
            TreeNode* tmpRoot = treeQ.front();
            treeQ.pop();
            TreeNode* temp = tmpRoot->left;
            tmpRoot->left = tmpRoot->right;
            tmpRoot->right = temp;
            if(tmpRoot->right != nullptr) treeQ.push(tmpRoot->right);
            if(tmpRoot->left != nullptr) treeQ.push(tmpRoot->left);
            
        }
        return root;
    }
};
