class Solution {
public:
    int minJumps(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        unordered_map<int,vector<int>> umap;
        for(int i=0; i<n; i++)
            umap[arr[i]].push_back(i);
        
        queue<int> q;
        q.push(0);
        vector<int> visited(n,0);
        visited[0] = 1;
        
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int t = q.front(); q.pop();
                if (t == n-1)
                    return res;
                if(t + 1 < n && visited[t+1]==0){
                    q.push(t+1);
                    visited[t+1] = 1;
                }
                if(t - 1 >=0 && visited[t-1]==0){
                    q.push(t-1);
                    visited[t-1] = 1;
                }
                for(auto &a: umap[arr[t]]){
                    if(visited[a]==0){
                        q.push(a);
                        visited[a] = 1;
                    }
                }
                umap.erase(arr[t]);
            }
            res +=1;
        }
        return -1;
    }
};