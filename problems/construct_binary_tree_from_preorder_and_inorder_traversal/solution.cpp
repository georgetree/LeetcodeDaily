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
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      
        unordered_map<int,int> m;
        for(int i=0; i<inorder.size(); i++)
            m[inorder[i]] = i;
        int r = 0;
        return helper(r,preorder,m,0,preorder.size()-1);
    }
    TreeNode* helper(int &r,vector<int>& preorder, unordered_map<int,int> &m, int left, int right){
        if(left > right) return NULL;
 
        TreeNode* root = new TreeNode(preorder[r]);
        int bound = m[preorder[r]];
   
        r++;
        root->left = helper(r,preorder,m,left,bound-1);
        root->right = helper(r,preorder,m,bound+1,right);
        return root;
    }
};