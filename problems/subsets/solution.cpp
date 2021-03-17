class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        dfs(result,nums,sub,0);
        return result;
    }
    
    void dfs(vector<vector<int>> &result, vector<int>& nums,vector<int>& sub,int start){
        result.push_back(sub);
        for(int i=start; i<nums.size(); i++){
            sub.push_back(nums[i]);
            dfs(result,nums,sub,i+1);
            sub.pop_back();
        }
    }
};