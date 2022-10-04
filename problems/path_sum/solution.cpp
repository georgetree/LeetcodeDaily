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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        return helper(root,targetSum);
    }
    bool helper(TreeNode *root, int t){
        if(root==nullptr) return false;
        t -= root->val;
        if(t==0 && (root->left==nullptr && root->right==nullptr)) return 1;
        bool l = helper(root->left,t);
        bool r = helper(root->right,t);
        return l | r;
    }
};