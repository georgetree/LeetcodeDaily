class RandomizedSet {
private:
    unordered_map<int,int> s;
    vector<int> r;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.count(val)) return false;
        r.push_back(val);
        s[val] = r.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!s.count(val)) return false;
        int l = r.back();
        s[l] = s[val];
        r[s[val]] = l; 
        r.pop_back();
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        return r[rand() % r.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */