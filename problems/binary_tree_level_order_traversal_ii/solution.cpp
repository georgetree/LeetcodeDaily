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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        TreeNode *n = root;
        int level = 0;
        levelOrder(result, n, level);
        return vector<vector<int>>(result.rbegin(),result.rend());
    }
    void levelOrder(vector<vector<int>> &result, TreeNode* n, int level){
        if(!n) return ;
        if(level==result.size()) result.push_back({});
        result[level].push_back(n->val);
        if(n->left) levelOrder(result,n->left,level+1);
        if(n->right) levelOrder(result,n->right,level+1);
    }
};