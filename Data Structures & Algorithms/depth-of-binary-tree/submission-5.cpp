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
       stack<pair<TreeNode*,int>> st;
       if(root == nullptr) {
        return 0;
       }
       int maxDepth = 0;
        st.push({root,1});
       while(!st.empty()) {
        auto i = st.top();
        st.pop();
        maxDepth = max(maxDepth, i.second);
        if(i.first->left != nullptr)
            st.push({i.first->left,i.second+1});
        if(i.first->right != nullptr)
            st.push({i.first->right,i.second+1});
       }
       return maxDepth;
    }
};
