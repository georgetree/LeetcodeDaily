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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        bTp(root,res,"");
        return res;
    }
    void bTp(TreeNode *root, vector<string> &res, string st){
        if(!root->left && !root->right)  res.push_back(st + to_string(root->val));
        if(root->left) bTp(root->left, res, st + to_string(root->val) + "->");
        if(root->right) bTp(root->right, res, st + to_string(root->val) + "->");
    }
};