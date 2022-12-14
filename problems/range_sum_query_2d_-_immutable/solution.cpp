class NumMatrix {
public:
    vector<vector<int>> res;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        res.resize(r+1,vector<int>(c+1,0));
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        // for(auto i:res){
        //     for(auto j:i)
        //         cout << j << '\t';
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // cout << res[row2][col2];
        return res[row2+1][col2+1] - res[row2+1][col1] - res[row1][col2+1] + res[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */