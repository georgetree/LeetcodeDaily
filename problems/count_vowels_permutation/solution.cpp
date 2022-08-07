class Solution {
public:
    
    // a -> e
    // e -> a,i
    // i -> a,e,o,u
    // o -> i,u
    // u -> a
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n,vector<long>(5,0));
        for(int i=0; i<5; i++) dp[0][i] = 1;
        int M  = 1e9+7;
        for(int i=1; i<n; i++){
            dp[i][0] += (dp[i-1][1] + dp[i-1][2] + dp[i-1][4]) % M;
            dp[i][1] += (dp[i-1][0] + dp[i-1][2]) % M;
            dp[i][2] += (dp[i-1][1] + dp[i-1][3]) % M;
            dp[i][3] += dp[i-1][2] % M;
            dp[i][4] += (dp[i-1][2] + dp[i-1][3])  % M;
        }
 
        return (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4])%M;
    }
};