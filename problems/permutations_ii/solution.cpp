class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> com;
        sort(nums.begin(),nums.end());

        vector<int> flag(nums.size(),0);
        dfs(result,com,nums,flag);
        return result;
    }
    void dfs(vector<vector<int>> &result, vector<int> &com, vector<int> &n, vector<int> &flag){
        if(com.size()==n.size()){ 
            result.push_back(com);
            return;
        }
        for(int i=0; i < n.size(); i++){
            if(flag[i]) continue; 
            if( i > 0 && flag[i-1]==0 && n[i] == n[i - 1]) continue;
            flag[i] = 1;
            com.push_back(n[i]);
            dfs(result,com,n,flag);
            com.pop_back();
            flag[i] = 0;
        }
    }
};