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
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        helper(root,res,0);
        return res;
    }
    void helper(TreeNode* root, int &res, int temp){
        if(root==nullptr) return;
        temp ^= (1 << root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(temp==0 || (temp & (temp-1))==0) res++;
        }
        helper(root->left,res,temp);
        helper(root->right,res,temp);
        
    }
};