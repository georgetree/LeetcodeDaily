class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        int len = r*c;
        vector<vector<int>> res(r,vector<int>(c));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int t = (i*c+j+k) % len; //攤平成一維
                res[t/c][t%c] = grid[i][j];
            }
        }
        return res;
    }
};