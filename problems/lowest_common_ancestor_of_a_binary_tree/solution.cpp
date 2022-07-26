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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr || root == q || root== p) return root;
        TreeNode* l =  helper(root->left,p,q);
        TreeNode* r =  helper(root->right,p,q);
        if(l==nullptr) return r;
        if(r==nullptr) return l;
        if(l && r) return root;
        return nullptr;
    }
};