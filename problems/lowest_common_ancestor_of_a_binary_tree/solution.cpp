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
        return helper(root,p,q);
    }
    TreeNode * helper(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == nullptr) return nullptr;
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode *l = helper(root->left,p,q);
        TreeNode *r = helper(root->right,p,q);
        if(l&&r) return root;
        return l != nullptr ? l : r;
    }
};