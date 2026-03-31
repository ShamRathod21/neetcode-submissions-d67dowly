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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) {
            return {};
        }
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                tmp.push_back(front->val);
                q.pop();
                if(front->left != nullptr)
                    q.push(front->left);
                if(front->right != nullptr)
                    q.push(front->right);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
    }
};
