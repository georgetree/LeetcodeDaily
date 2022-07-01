class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const auto a, const auto b){
            return a[1] > b[1];
        });
        int res = 0;
        for(auto boxType:boxTypes){
            int t = min(truckSize,boxType[0]);
            res+= t*boxType[1];
            truckSize -= boxType[0];
            if(truckSize<=0) break;
        } 
        return res;
    }
};