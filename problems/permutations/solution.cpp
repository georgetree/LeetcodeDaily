class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res,temp,nums);
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> temp, vector<int> &nums){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(find(temp.begin(),temp.end(),nums[i])!=temp.end()) continue;
            temp.push_back(nums[i]);
            helper(res,temp,nums);
            temp.pop_back();
        }
        
    }
};