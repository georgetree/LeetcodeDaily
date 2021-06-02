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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSym(root->left,root->right);
    }
    bool isSym(TreeNode *l,TreeNode *r){
        if(!l && !r) return true;
        if(!l || !r || l->val != r->val ) return false;
        return isSym(l->left, r->right) && isSym(l->right, r->left);
    }
};