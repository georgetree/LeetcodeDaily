class Solution {
public:
    bool isMatch(string s, string p) {
        int strlen = s.size(), explen = p.size();
        vector<vector<bool>> dp(strlen+1,vector<bool>(explen+1,false));
        if(p[0]=='*')
            return false;
        dp[0][0] = true;

        for(int i = 1; i <= explen; ++i)
            if(p[i-1] == '*' && dp[0][i-2])
                dp[0][i] = true;
        for(int i = 1; i <= strlen; ++i){
            for(int j = 1; j <= explen; ++j){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(s[i-1] != p[j-2] ){
                        dp[i][j] = dp[i][j-2];
                    }
                    if(s[i-1] == p[j-2] || p[j-2] == '.'){
                        dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j]  ;
                    }
                }
            }
        }
        return dp[strlen][explen];
    }
};