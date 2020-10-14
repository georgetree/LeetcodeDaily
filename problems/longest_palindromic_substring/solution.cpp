class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int maxlen = 1;
        int start = {};

    for(int i = 0; i < s.length(); ++i){
        dp[i][i] = 1;
    }
    for(int i = 1; i < s.length(); ++i){
        for(int j = 0; j < i; ++j){
            if(s[i] == s[j]){
                if(i-j<3)
                    dp[j][i] = 1;
                else 
                    dp[j][i] = dp[j+1][i-1];
            }
            else{
                dp[j][i] = 0; 
            }
            if(dp[j][i] && i-j+1 > maxlen){
                start = j ;
                maxlen = i-j+1;
            }
        } 
    }
    return s.substr(start,maxlen);
    }
};


 