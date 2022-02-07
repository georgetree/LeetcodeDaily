class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(char i:s+t)
            res ^=i;
        return res;
    }
};