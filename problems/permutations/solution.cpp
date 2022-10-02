class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> p;
        helper(nums,res,p);
        return res;
    }
    void helper(vector<int>& nums,vector<vector<int>> &res,vector<int>& p){
        if(p.size()==nums.size()){
            res.push_back(p);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(find(p.begin(),p.end(),nums[i])!=p.end()) continue;
            p.push_back(nums[i]);
            helper(nums,res,p);
            p.pop_back();
        }
    }
};