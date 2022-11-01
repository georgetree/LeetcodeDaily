class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> res;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<n; i++){
            int col = i;
            int nextD = 0;
            for(int j=0; j<m; j++){
                nextD = grid[j][col] + col;
                if(nextD < 0 || nextD >= n || grid[j][col] != grid[j][nextD]){
                    col = -1;
                    break;
                }
                col = nextD;
            }
            res.push_back(col);
        }
        return res;
    }
};