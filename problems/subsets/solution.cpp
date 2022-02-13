class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,tmp,nums,0);
        return res;
    }
    
    void dfs(vector<vector<int>> &res, vector<int> &t, vector<int> &nums, int start){
        res.push_back(t);
        for(int i=start; i<nums.size(); i++){
            t.push_back(nums[i]);
            dfs(res,t,nums,i+1);
            t.pop_back();
        }
    }
};