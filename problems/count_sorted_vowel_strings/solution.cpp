class Solution {
public:
    int countVowelStrings(int n) {
        // c n+m-1 取 m = c n+4 取 4 
        return (n+4) * (n+3)  * (n+2) * (n+1) /24;
    }
};