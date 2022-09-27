class Trie {
private:
    Trie *child[26];
    bool isEnd;
public:
    Trie(){
        isEnd = false;
        for(auto &i:child) i = nullptr;
    }
    void insert(string word) {
        Trie *r = this;
        for(auto &w:word){
            if(r->child[w-'a'] == nullptr){
                r->child[w-'a'] = new Trie();
            }
            r = r->child[w-'a'];
        }
        r->isEnd = true;
    }
    
    bool search(string word) {
        Trie *r = this;
        for(auto &w:word){
            r = r->child[w-'a'];
            if(r==nullptr)
               return false;
        }
        return r->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *r = this;
        for(auto &p: prefix){
            r = r->child[p-'a'];
            if(r==nullptr)
               return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */