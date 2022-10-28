class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), dp[n][n];
        int maxLen = 0, start = 0;
        int l = 0;
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
            for(int j=0; j<=i; j++){
                if(s[j]!=s[i]) dp[i][j] = 0;
                else{
                    if(i-j < 3) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j+1];
                }
                if(dp[i][j] && i-j+1 > maxLen){
                    maxLen = max(maxLen, i-j+1);
                    start = j;
            }
        }
        }
        return s.substr(start,maxLen);
    }
};