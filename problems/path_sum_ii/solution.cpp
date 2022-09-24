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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        vector<int> path;
        helper(root,targetSum,path,res);
        return res;
    }
    void helper(TreeNode *root, int target,vector<int> &path, vector<vector<int>> &res){
        if(root==nullptr) return;
        path.push_back(root->val);
        if(root->val==target && root->left==nullptr && root->right==nullptr) {
            res.push_back(path);
        }
        
        helper(root->left,target-root->val,path,res);
        helper(root->right,target-root->val,path,res);
        path.pop_back();

    }
};