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
    int goodNodes(TreeNode* root) {
        int res = 0;
        helper(root,res,root->val);
        return res;
    }
    void helper(TreeNode *root, int &res, int m){
        if(root==nullptr) return;
        if(root->val>=m) {
            res++;
            m = root->val;
        }
        helper(root->left,res,m);
        helper(root->right,res,m);
 
    }
};