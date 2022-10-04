class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = 0, s = 0;
        for(int i=0; i<m*n; i++){
            res.push_back(matrix[x][y]);
            matrix[x][y] = 0;
            int nx = x + dir[s][0];
            int ny = y + dir[s][1];
            if(nx<0 || nx>=m || ny<0 || ny>=n || matrix[nx][ny]==0){
                s = (s+1)%4;
                nx = x + dir[s][0];
                ny = y + dir[s][1];
            }
            x = nx;
            y = ny;
        }
        return res;
    }
};