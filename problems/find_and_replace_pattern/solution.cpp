class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
 
        for(auto word:words){
            unordered_map<char,char> m,n;
            bool flag = true;
            for(int i=0; i<pattern.size(); i++){
                if(m.count(word[i]) && m[word[i]]!=pattern[i]) {
                    flag = false;
                    break;
                }
                m[word[i]] = pattern[i];
                if(n.count(pattern[i]) && n[pattern[i]] != word[i] ){
                    flag = false;
                    break;
                } 
                n[pattern[i]] = word[i];
            }
            if(flag) res.push_back(word);
        }
        return res;
    }
};