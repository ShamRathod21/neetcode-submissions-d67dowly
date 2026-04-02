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
    int res = INT_MIN;
    int maxVal(TreeNode* root) {
        if(!root)
            return 0;
        int left = maxVal(root->left);
        int right = maxVal(root->right);
        return max(0,root->val + max(left, right));
    }
    void dfs(TreeNode* root) {
        if(!root)
            return;
        int left = maxVal(root->left);
        int right = maxVal(root->right);
        res =  max(res,root->val + left + right);
        dfs(root->left);
        dfs(root->right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
