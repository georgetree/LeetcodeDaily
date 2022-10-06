class LRUCache {
public:
    int c;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    list<pair<int,int>> l;
    LRUCache(int capacity): c(capacity) {
        
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        auto it = m[key];
        l.splice(l.begin(),l,it);
        return it->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) l.erase(it->second);
        l.push_front({key,value});
        m[key] = l.begin();
        if(l.size() > c){
            m.erase(l.back().first);
            l.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */