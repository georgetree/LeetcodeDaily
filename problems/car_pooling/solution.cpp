class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> m;
        for(auto &i: trips){
            m[i[1]] += i[0] ;
            m[i[2]] -= i[0] ;
        }
        
        for(auto &j:m){
            capacity -= j.second;
            if(capacity < 0) return false;
        }
        return true;
    }
};