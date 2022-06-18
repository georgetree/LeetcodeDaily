class WordFilter {
public:
    unordered_map<string,int> m;
    WordFilter(vector<string>& words) {
        
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<=words[i].size();j++){
                for(int k=0; k<=words[i].size();k++){
                    m[words[i].substr(0,j) + "_" + words[i].substr(words[i].size()-k)] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string t = prefix + "_" + suffix;
        return (m.count(t)) ? m[t] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */