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
    int deepestLeavesSum(TreeNode* root) {
        int i = 0, res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            for(i=q.size(), res=0; i>0; i--){
                auto t = q.front();
                q.pop();
                res += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return res;
    }
};