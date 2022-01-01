class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp (n+2,vector<int>(n+2,0));
        for(int k = 2; k < n; k++){
            for(int l = 0; l < n - k  ; l++){
                int r = l + k;
                for(int i = l+1; i < r ;i++){
                    dp[l][r] = max(dp[l][r],dp[l][i] + dp[i][r] + nums[l]*nums[i]*nums[r]);
                }
            }
        }
        return dp[0][n-1];
    }
};