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
        queue<TreeNode*> dp;
        if(root ==nullptr)
            return 0;
        dp.push(root);
        int depth = 0;
        while(!dp.empty()) {
            int size = dp.size();
            while(size--) {
                auto node = dp.front();
                dp.pop();
                if(node->left != nullptr) dp.push(node->left) ;
                if(node->right != nullptr) dp.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
