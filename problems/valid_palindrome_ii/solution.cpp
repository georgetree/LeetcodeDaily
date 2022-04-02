class Solution {
public:
    bool validPalindrome(string s) {
        int p1,p2;
        int n = s.size()-1;
        for(int i=0; i<=n/2; i++){
            p1 = i;
            p2 = n-i;
            if(s[p1] != s[p2]){
                return vaild(s,p1+1,p2) || vaild(s,p1,p2-1); 
            }
        }
        return true;
    }
    bool vaild(string s, int l, int r){
        while(l < r){
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
};
