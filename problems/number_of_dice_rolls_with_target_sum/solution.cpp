class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int M = 1000000007;
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            vector<int> t(target + 1);
            for(int j=1; j<=k; j++){
                for(int m=j; m<=target; m++){
                    t[m] = (t[m] + dp[m-j]) % M;
                }
            }
            swap(dp,t);
        }
        return dp[target];
    }
};