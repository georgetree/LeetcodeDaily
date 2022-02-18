class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> m;
        string res = "";
        for(auto i:s){
            m[i]+=1;
        }
        for(auto i:s){
            m[i]-=1;
            if(res.find(i) != string::npos) continue;
            while(m[res.back()] > 0 && !res.empty() && res.back() > i ){
                res.pop_back();
            }
            res.push_back(i);
        }
        return res;
    }
};