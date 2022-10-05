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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *r = new TreeNode(val);
            r->left = root;
            return r;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            depth -= 1;
            int len = q.size();
            for(int i=0; i<len; i++){
                TreeNode *temp = q.front();
                if(depth==1){
                    TreeNode *tl = temp->left;
                    TreeNode *tr = temp->right;
                    TreeNode *newnode1 = new TreeNode(val,tl,nullptr);
                    TreeNode *newnode2 = new TreeNode(val,nullptr,tr);
                    temp->left = newnode1;
                    temp->right = newnode2;
                }
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        
        return root;
    }
};