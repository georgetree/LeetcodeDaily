class Solution {
public:
    vector<vector<int>> newD = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.emplace(i,j);
                    
                }
                else mat[i][j] = -1;
            }
        }
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + newD[i][0];
                int ny = y + newD[i][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny] == -1){{
                    mat[nx][ny] = mat[x][y]+1;
                    q.emplace(nx,ny);
                }}
            }
        }
        return mat;
    }
  
};