class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m;
        for(auto &s: magazine)
            m[s]++;
        for(auto &r:ransomNote){
            if(m[r]>0)
                m[r]--;
            else return false;
        }
        return true;
    }
};