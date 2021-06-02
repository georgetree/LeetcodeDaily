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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        TreeNode *n = root;
        int level = 0;
        levelorder(res,level,n);
        return res;
    }
    void levelorder(vector<vector<int>> &res,int level, TreeNode *n){
        if(!n) return;
        if(res.size()==level) res.push_back({}); //新增二維vector層數 
        res[level].push_back(n->val);
        if(n->left) levelorder(res, level+1, n->left);
        if(n->right) levelorder(res, level+1, n->right);

    }
};