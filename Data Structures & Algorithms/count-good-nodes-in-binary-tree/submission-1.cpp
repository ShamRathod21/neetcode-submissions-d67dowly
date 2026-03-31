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

    int dfs(TreeNode* node, int maxVal) {
        if(!node)
            return 0;
        int res = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal,node->val);
        res += dfs(node->left,maxVal);
        res += dfs(node->right,maxVal);
        return res;
    }
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if(!root)
            return 0;
        int finRes = 0;
        q.push({root,root->val});
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                pair<TreeNode*,int> p = q.front();
                q.pop();
                int res = p.first->val >= p.second ? 1 : 0;
                finRes += res;
                if(p.first->left) {
                    q.push({p.first->left,max(p.second,p.first->left->val)});
                }
                if(p.first->right) {
                    q.push({p.first->right,max(p.second,p.first->right->val)});
                }
            }
        }
        return finRes;
    }
};
