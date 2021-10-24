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
    int countNodes(TreeNode* root) {
        int res, level_l, level_r;
        if(!root) return 0;
        level_l = countLevel(root->left);
        level_r = countLevel(root->right);
        if (level_l==level_r) return res = pow(2,level_l) + countNodes(root->right);
        return res = pow(2,level_r) + countNodes(root->left);
    }
    
    int countLevel(TreeNode* root){
        int level=0;
        while(root){
            level+=1;
            root=root->left;  
        }
        return level;
    }
};