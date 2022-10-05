class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return {};
        vector<int> m1(256,0),m2(256,0);
        vector<int> res;
        for (int i = 0; i < p.size(); ++i) {
            ++m1[s[i]]; ++m2[p[i]];
        }

        if (m1 == m2) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++m1[s[i]]; 
            --m1[s[i - p.size()]];
            if (m1 == m2) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};