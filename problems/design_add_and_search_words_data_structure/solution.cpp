class WordDictionary {
public:
    unordered_map<int,vector<string>> map;
    bool equal(string a, string b){
        for(int i=0; i<a.size(); i++){
            if(b[i] == '.') continue;
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    WordDictionary() {
    }
    
    void addWord(string word) {
        map[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto i:map[word.size()]){
            if(equal(i,word)) return true;
    
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */