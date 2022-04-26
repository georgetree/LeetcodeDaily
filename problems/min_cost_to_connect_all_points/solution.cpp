class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<bool> t(points.size(),false);
        pq.push({0,0});
        int res = 0;
        int pointsLen = points.size();
        
        while(!pq.empty() && pointsLen>0){
            auto [d,i] = pq.top();
            pq.pop();
            if(t[i]) continue;
            t[i] = true;
            pointsLen--;
            res+=d;
            
            for(int j=0; j<points.size(); j++){
                if(t[j]) continue;
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push({dis,j});
            }
            
        }
        return res;
    }
};