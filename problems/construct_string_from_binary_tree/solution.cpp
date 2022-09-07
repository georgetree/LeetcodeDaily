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
    string tree2str(TreeNode* root) {
        string res = "";
        helper(root,res);
        return string(res.begin()+1,res.end()-1);
    }
    void helper(TreeNode *root,string &res){
        if(root==nullptr) return;
        res+= "(" + to_string(root->val);
        if(root->left==nullptr && root->right) res += "()";
        helper(root->left,res);
        helper(root->right,res);
        res+= ")";
    }
};