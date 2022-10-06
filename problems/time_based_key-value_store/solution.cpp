class TimeMap {
public:
    unordered_map<string,vector<pair<int, string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = m[key].size();
        while(l<r){
            int mid = (r-l)/2 + l;
            if(m[key][mid].first > timestamp) r = mid;
            else l = mid + 1;
        }
        return l > 0  ? m[key][l-1].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */