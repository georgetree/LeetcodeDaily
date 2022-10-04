class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums,res,0,temp);
        return res;
    }
    void helper(vector<int> &nums, vector<vector<int>> &res,int t, vector<int> temp){
        res.push_back(temp);
        for(int i=t; i<nums.size(); i++){
            temp.push_back(nums[i]);
            helper(nums,res,i+1,temp);
            temp.pop_back();
        }
    }
};