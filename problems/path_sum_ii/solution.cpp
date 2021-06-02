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
        vector<vector<int>> res;
        vector<int> node;
        hasPathSum(root, targetSum, res, node);
        return res;
        
    }
    void hasPathSum(TreeNode* root, int targetSum, vector<vector<int>> &res, vector<int> &node){
        if(!root) return;
        node.push_back(root->val);
        if(!root->left && !root->right && targetSum==root->val){
            res.push_back(node);
        } 
        if(root->left) hasPathSum(root->left,targetSum-(root->val), res, node); 
        if(root->right) hasPathSum(root->right,targetSum-(root->val), res, node);
        node.pop_back();

    }
};