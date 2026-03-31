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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        queue<TreeNode*> pQ,qQ;
        pQ.push(p);
        qQ.push(q);

        while(!pQ.empty() && !qQ.empty()) {
            p = pQ.front(); pQ.pop();
            q = qQ.front(); qQ.pop();
            if(!p && !q) {
                continue;
            }
            if( !p || !q || p->val != q->val)
            return false;
            pQ.push(p->left);
            qQ.push(q->left);
            pQ.push(p->right);
            qQ.push(q->right);
        }

        return true;

        // }
        // if(!p && !q) {
        //     return true;
        // }

        // if( !p || !q || p->val != q->val)
        //     return false;
        // return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
