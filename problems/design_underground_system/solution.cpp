class UndergroundSystem {
public:
    unordered_map<int,pair<int,string>> n;
    unordered_map<string,pair<int,double>>m;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        n[id] = make_pair(t,stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        string temp = stationName+"_"+n[id].second;
        m[temp].first += 1;
        m[temp].second += t-n[id].first;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string t = endStation + "_" + startStation;
        return m[t].second / m[t].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */