/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        TreeNode* res = root;
        // if(root->val >= p->val) return root;
        if(root->val < p->val && root->val < q->val) res = lowestCommonAncestor(root->right,p,q);
        if(root->val > p->val && root->val > q->val) res = lowestCommonAncestor(root->left,p,q);
        return res;
    }
};