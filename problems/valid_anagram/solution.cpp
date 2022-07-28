class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        for(auto j:t){
            if(m[j]>=1) m[j]--;
            else return false;
        }
        return true;
    }
};