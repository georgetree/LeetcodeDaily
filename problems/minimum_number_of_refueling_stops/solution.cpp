class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>q;
        int cur = startFuel;
        int res = 0;
        int i=0;
        while(cur < target){
            if(i<stations.size() && cur >= stations[i][0])
                q.push(stations[i++][1]);
            else{
                if(q.empty()) return -1;
                cur += q.top();
                q.pop();
                res++;
            }
        }
        return res;
    }
};