class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j])
                    res = max(res,helper(grid,i,j));
            }
        }
        return res; 
    }
    int helper(vector<vector<int>>& grid, int x, int y){
        if( x>=0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1){
            grid[x][y] = 0;
            return 1 + helper(grid,x+1,y) + helper(grid,x-1,y) + helper(grid,x,y+1) + helper(grid,x,y-1);
        }
        return 0;
    }
};