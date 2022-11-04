class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(auto c:s){
            m[c]++;
        }
        bool f = 0;
        int res = 0;
        for(auto [k,v]: m){
            res += v;
            if(v & 1){
                f = 1;
                res--;
            } 
            
        }
        return f==1 ? res+1 : res;
    }
};