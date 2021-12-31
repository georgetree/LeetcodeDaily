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
    int dfs(TreeNode *root, int cmin, int cmax){
        if(root==NULL) return cmax - cmin;
        cmin = min(cmin,root->val);
        cmax = max(cmax,root->val);
        return max(dfs(root->left,cmin,cmax),dfs(root->right,cmin,cmax));
    }
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        int min = INT_MAX; 
        int max = INT_MIN;

        res = dfs(root,min,max);
        return res;
    }
};