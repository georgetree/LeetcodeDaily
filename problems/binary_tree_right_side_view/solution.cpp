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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root!=NULL){
            q.emplace(root);
        }
        while(!q.empty()){
            int l = q.size();
            res.push_back(q.back()->val);
            for(int i=0; i<l; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    q.emplace(temp->left);
                } 
                if(temp->right){
                    q.emplace(temp->right);

                }
            }
        }
        return res;
    }
};