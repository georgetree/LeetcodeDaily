class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        dp[0] = 1;
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<=i; j++){
                if(st.count(s.substr(j,i-j)) && dp[j]){
                    dp[i] = 1;
                    break;
                }
                    
            }
        }
        return dp.back();
    }
};