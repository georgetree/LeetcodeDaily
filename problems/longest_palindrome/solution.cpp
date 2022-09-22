class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>st(100,0);
        for(char i:s)
            st[i-'A']++;
        int sumOdd = 0; 
        for(int &i:st){
            sumOdd += i&1;
        }
        return s.size() - sumOdd + (sumOdd>0);
    }
};