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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxP(root, res);
        return res;
    }
    int maxP(TreeNode *root,int &res){
        if(!root) return 0;
        int l = max(maxP(root->left,res),0);
        int r = max(maxP(root->right,res),0);
        res = max(res,l + r + root->val);
        int t = max(l,r) + root->val;
        return t;
    }
};