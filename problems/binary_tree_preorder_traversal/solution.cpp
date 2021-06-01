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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {}; 
        stack<TreeNode*> s;
        s.push(root);
        vector<int> result;
        while(!s.empty()){
            TreeNode* n = s.top();
            s.pop();
            result.push_back(n->val);
            if(n->right) s.push(n->right);
            if(n->left) s.push(n->left);
        }
        
        return result;
    }
};