class Solution {
public:
    string longestPalindrome(string s) {
        int curlen = 0;
        int start = 0;
        int n = s.size(), dp[n][n];
        for(int i=0; i<s.size(); i++) {
            dp[i][i] = 1;
            for(int j=0; j<=i; j++) {
                if(s[i]!=s[j]){
                    dp[i][j] = 0;
                }
                else{
                    if(i-j < 3) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i-1][j+1];
                    }
                }
                if(dp[i][j] && i-j+1 > curlen){
                    curlen = i-j+1;
                    start = j;
                }
            }
        }
        return s.substr(start,curlen);
        
    }
};