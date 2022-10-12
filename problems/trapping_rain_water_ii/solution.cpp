class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    q.push({heightMap[i][j],i*n+j});
                    vis[i][j] = true;
                }
            }
        }
        int h = INT_MIN;
        while(!q.empty()){
            auto [v,d] = q.top();
            q.pop();
            int x = d/n; 
            int y = d%n;
            h = max(h,v);
            for(int i=0; i<4; i++){
                int nx = dir[i][0] + x;
                int ny = dir[i][1] + y;
                if(nx<0 || nx>=m || ny<0 || ny>=n || vis[nx][ny]) continue; 
                vis[nx][ny] = true;
                if(heightMap[nx][ny] < h) res += h-heightMap[nx][ny];
                q.push({heightMap[nx][ny], nx*n+ny});
            }
        }
        return res;
    }
};