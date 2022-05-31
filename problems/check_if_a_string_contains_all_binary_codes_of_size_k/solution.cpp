class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return false;
        unordered_set<string> m;
        for(int i=0; i<=s.size()-k; i++){
            m.insert(s.substr(i,k));
        }
        return m.size() == pow(2,k);
    }
};