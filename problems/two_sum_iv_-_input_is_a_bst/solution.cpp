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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        helper(root,nums);
        int l=0, r=nums.size()-1;
        while(l<r){
            int res = nums[l]+nums[r];
            if(res== k) return true;
            else if(res>k) --r;
            else ++l;
        }
        return false;
    }
    void helper(TreeNode *root, vector<int> &nums){
        if(root==nullptr) return;
        helper(root->left, nums);
        nums.push_back(root->val);
        helper(root->right, nums);
    }
};