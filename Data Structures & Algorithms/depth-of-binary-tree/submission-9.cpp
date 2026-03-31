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
        deque<TreeNode*> q;
        int depth = 0;
        if(root == nullptr) 
            return 0;
            q.push_back(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n;i++) {
                TreeNode* temp = q.front();
                q.pop_front();
                if(temp->left) q.push_back(temp->left);
                if(temp->right) q.push_back(temp->right);
            }
            depth++;
        }
        return depth;
    }
};
