class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //dp[i] = dp[target-nums[i]](i>=0 && i < nums.size())
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1; //num剛好等於target 
        for(int i=1; i<=target; i++){
            for(int num:nums){
                if(num > i) continue;
                dp[i] += dp[i-num];
            }
        }
        return dp[target];
    }
};