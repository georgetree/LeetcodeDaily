class LRUCache {
public:
    int c;
    LRUCache(int capacity) : c{capacity}{}
    list <pair<int,int>> li;
    unordered_map <int , list<pair<int,int>>::iterator > um;
    int get(int key) {
        auto v = um.find(key);
        if( v == um.end()) { //沒在map裡
            return -1;
        }
        li.splice(li.begin(), li, v->second); //push value到前面
        return v->second->second;
    }
    
    void put(int key, int value) {
        if(get(key) != -1) { //已經在map裡面
            um[key]->second = value; 
            return;
        }
        if(c == um.size()){
            auto temp = li.back().first;
            li.pop_back();
            um.erase(temp);    
        }
        li.emplace_front(key, value);
        um[key] = li.begin();
   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */