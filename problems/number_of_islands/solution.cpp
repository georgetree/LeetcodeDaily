class Solution {
public:
    vector<vector<int>> dr = {{0,1},{1,0},{0,-1},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    res+=1;
                    helper(i,j,grid);
                }
            }
        }
        return res;
    }
    void helper(int x, int y, vector<vector<char>>& grid){
        if(grid[x][y] == '0') return;
        grid[x][y] = '0';
        for(int i=0; i<4; i++){
            int nx = x + dr[i][0];
            int ny = y + dr[i][1];
            if(nx>=0 && nx < grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]=='1')
                helper(nx,ny,grid);
        }
        
    }
};