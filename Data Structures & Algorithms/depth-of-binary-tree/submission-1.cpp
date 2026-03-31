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
        if(root == nullptr)
            return 0;
        deque<TreeNode*> q;
        q.push_back(root);
        int level = 0;
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                TreeNode* first = q.front();
                q.pop_front();
                if(first->left)
                    q.push_back(first->left);
                if(first->right)
                    q.push_back(first->right);
            }
            level++;
        }
        return level;
    }
};
