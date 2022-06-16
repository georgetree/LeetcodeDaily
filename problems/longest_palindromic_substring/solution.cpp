class Solution {
public:
    string longestPalindrome(string s) {
        int cur = 0, n = s.size(), l = 0, r = 0, curL = 0, curR = 0;
        while(cur<n){
            l = cur;
            r = cur;
            for(;r < n-1 && s[r] == s[r+1]; r++);
            cur = r+1;
            for(;l>0 && r < n-1 && s[l-1] == s[r+1];l--,r++);
            if(r-l > curR-curL){
                curR = r;
                curL = l;
            }
        }
        return s.substr(curL,curR-curL+1);
    }
};