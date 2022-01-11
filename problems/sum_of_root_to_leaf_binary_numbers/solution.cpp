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
    int sumRootToLeaf(TreeNode* root) {
        int t = 0;
        int res = dfs(root,t);
        return res;
    }
    
    int dfs(TreeNode *root, int res){
        if(!root) return 0;
        res = 2*res + root->val;
        return root->left != root->right ? dfs(root->left,res)+ dfs(root->right,res) : res;
    }
};