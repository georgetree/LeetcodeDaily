class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> newdir = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int fresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1) ++fresh;
            }
        }
        while(!q.empty() && fresh>0){
            int len = q.size();
            for(int i=0; i<len; i++){
                auto [x,y] = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    int nx = newdir[k][0]+x;
                    int ny = newdir[k][1]+y;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                        --fresh;
                    }
                }
            }
            res++;
        }
   
        return fresh > 0 ? -1 : res;
    }
};