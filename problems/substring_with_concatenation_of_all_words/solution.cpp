class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = words.size();
        int len = words[0].size();
        unordered_map<string,int> m;
        for(auto w:words)
            ++m[w];
     
        for(int i=0; i<s.size()-n*len+1; i++){
            unordered_map<string,int> t;
            int j=0;
            for(; j<n; j++){
                string st = s.substr(i+j*len,len);
                if(m.find(st) == m.end()) break;
                ++t[st];
                if(t[st] > m[st]) break;
            }
            if(j==n) res.push_back(i);
        }
        return res;
    }
};