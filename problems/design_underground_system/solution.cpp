class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>m1;
    unordered_map<string,pair<double,int>>m2;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        m1[id] = make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        stationName = m1[id].first+ "_" +stationName;
        m2[stationName].first += t - m1[id].second;
        m2[stationName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string t = startStation + "_" + endStation;
        double res = m2[t].first / m2[t].second;
        return res;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */