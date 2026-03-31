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
    int maxDepth(TreeNode* root) {
       if(root == nullptr) {
        return 0;
       }
       queue<TreeNode*> treeQ;
       treeQ.push(root);
       int depth = 0;
       while(!treeQ.empty()) {
        int len = treeQ.size();
        for(int i = 0; i < len ; i++) {
            TreeNode* front = treeQ.front();
            treeQ.pop();
            if(front->left) 
                treeQ.push(front->left);
            if(front->right) 
                treeQ.push(front->right);
        }
        depth++;
       }
       return depth;
    }
};
