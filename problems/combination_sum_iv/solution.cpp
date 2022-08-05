class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<uint> dp(target+1,0);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            for(auto const &num:nums){
                if(num>i) continue;
                dp[i] += dp[i-num];
            }
        }
        return dp.back();
    }
};