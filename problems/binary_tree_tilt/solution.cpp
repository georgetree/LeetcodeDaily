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
    int res;
    int findTilt(TreeNode* root) {
        DFS(root);
        return res;
    }
    
    int DFS(TreeNode *root){
        if (!root) return 0; 
        int l = DFS(root->left);
        int r = DFS(root->right);
        
        res += abs(l-r);
        return l + r + root->val;
    }
};