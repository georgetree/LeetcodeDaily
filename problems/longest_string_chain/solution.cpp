class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int> m;
        sort(words.begin(),words.end(),[&](string a, string b){
            return a.size() < b.size();
        });
        int res = 0;
        for(auto w:words){
            for(int j=0; j<w.size(); j++){
                string t = w.substr(0,j) + w.substr(j+1);
                m[w] = max(m[w],m[t]+1);
            }
            res = max(res,m[w]);
        }
      
        return res;
    }
};