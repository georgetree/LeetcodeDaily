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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *n = root;
        stack<TreeNode*> s;
        while(n||!s.empty()){
            while(n){
                s.push(n);
                n = n->left;
            }
            n = s.top(); s.pop();
            res.push_back(n->val);
            n = n->right;
        }
        return res;
    }
};