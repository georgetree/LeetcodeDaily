class Solution {
public:
    int numDecodings(string s) {
        // vector<int> dp(s.size(),0);
        // dp[0] = 1;]
        if (s[0] == '0') return 0;

        int a = 1, b = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i]=='0'){
                if(s[i-1]=='1' || s[i-1]=='2') {
                    a = b;
                }
                else return 0;
            } 
            else if(s[i-1]=='1' || (s[i-1]=='2' && s[i] <= '6' && s[i] >= '0')){
                a = a + b;
                b = a-b;
            }
            else b = a;
        }
       
        return a;
    }
};