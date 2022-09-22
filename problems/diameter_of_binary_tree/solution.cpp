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
    int diameterOfBinaryTree(TreeNode* root) {
        int h = 0;
        helper(root,h);
        return h;
    }
    int helper(TreeNode *root,int &h){
        if(root==nullptr) return 0;
        int l = helper(root->left,h);
        int r = helper(root->right,h);
        h = max(h,l+r);
        return max(l,r)+1;
    }
};