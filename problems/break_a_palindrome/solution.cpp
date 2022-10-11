class Solution {
public:
    string breakPalindrome(string p) {
        int r = p.size();
        for(int i=0; i<r/2; i++){
            if(p[i]!='a') {
                p[i] = 'a';
                return p;
            }
        }
        p.back() = 'b';
        return p.size() < 2 ? "" : p;
    }
};