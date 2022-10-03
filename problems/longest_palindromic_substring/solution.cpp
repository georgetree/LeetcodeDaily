class Solution {
public:
    string longestPalindrome(string s) {
        int m = s.size();
        vector<vector<int>> dp(m,vector<int>(m));
        int start = 0;
        int curlen = 1;
        for(int i=1; i<m; i++){
            dp[i][i] = 1;
            for(int j=0; j<=i; j++){
                if(s[i]==s[j]){
                    if(i-j < 3) dp[i][j] = 1;
                    else{
                        dp[i][j] = dp[i-1][j+1];
                    }
                }
                else{
                    dp[i][j] = 0;
                }
                if(dp[i][j] && (i-j+1) > curlen ){
                    start = j;
                    curlen = i-j+1;
                }
            }
        }
        return s.substr(start,curlen);
    }
};