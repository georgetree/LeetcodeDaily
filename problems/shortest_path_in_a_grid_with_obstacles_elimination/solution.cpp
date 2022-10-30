class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = k;
        queue<vector<int>> q;
        q.push({0,0,k});
        int res = 0;
        while(!q.empty()){
            for(int i=q.size(); i>0; i--){
                auto v = q.front();
                q.pop();
                if(v[0]==m-1 && v[1]==n-1) return res;
                 
                for(int j=0; j<4; j++){
                    int nx = v[0] + dir[j][0];
                    int ny = v[1] + dir[j][1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    int newK = v[2] - grid[nx][ny];
                    if(newK < 0 || newK <= visited[nx][ny]) continue;
                    visited[nx][ny] = newK;
                    q.push({nx,ny,newK});
                }
            }   
            ++res;
        }
        return -1;
    }
};