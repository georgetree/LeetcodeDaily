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
        if(root==nullptr || root==p || root==q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        if (l && l != p && l != q) return l;
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(r && l) return root;
        return l ? l : r;
    }
};