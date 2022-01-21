class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=0, res=0, t=0;
        for(int i=0; i<gas.size(); i++){
            res += gas[i] - cost[i];
            t += gas[i] - cost[i];
            if(res < 0){
                res = 0;
                s = i + 1;
            }
        }
        return t < 0 ? -1 : s;
    }
};