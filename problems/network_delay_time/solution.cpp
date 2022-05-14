class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using Pair = pair<int,int>;
        vector<vector<Pair>> graph(n+1);
        //vector<int> seen(n+1,0);
        vector<int> dist(n+1,INT_MAX);
        for(auto t: times) 
            graph[t[0]].push_back({t[2],t[1]});
        priority_queue<Pair,vector<Pair>,greater<Pair>>pq;
        pq.push({0,k});
        dist[k] = 1;
        int res = 0;
        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();

            //res = max(res,dis);
            for(auto &[d,n]:graph[node]){
                if(dist[n] > d+dis){
                    pq.push({dis+d,n});
                    dist[n] = d+dis;
                }    
            } 
        }
        
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            res=max(res,dist[i]);
        }

        return res;
    }
};