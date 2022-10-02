class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int M = 1e9 + 7;
        vector<vector<int>> dp(n+1,vector<int>(target+1));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                for(int m=j; m<=target; m++){
                    dp[i][m] = (dp[i][m] + dp[i-1][m-j]) % M;
                }
            }
        }
        return dp[n][target];
    }
};