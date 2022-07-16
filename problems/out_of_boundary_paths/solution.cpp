class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n, 0)));
        for(int k=1; k<=maxMove; k++){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    long d1 = i==0 ? 1 : dp[k-1][i-1][j];
                    long d2 = j==0 ? 1 : dp[k-1][i][j-1];
                    long d3 = i==(m-1) ? 1 : dp[k-1][i+1][j];
                    long d4 = j==(n-1) ? 1 : dp[k-1][i][j+1];
                    dp[k][i][j] = (d1+d2+d3+d4) % 1000000007;
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};