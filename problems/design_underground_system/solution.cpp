class UndergroundSystem {
private:
    unordered_map<int,pair<string,int>> m1;
    unordered_map<string,pair<int,double>> m2;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m1[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s= stationName + "_" + m1[id].first;
        m2[s].first +=1;
        m2[s].second += t - m1[id].second;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = endStation + "_" + startStation;
        return m2[s].second / m2[s].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */