class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<string> board(n,string(n,'.'));
        solve(board,res,0,n);
        return res;
    }
    void solve(vector<string> &board,int &res,int row, int n){
        if(row == n){
            res++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (valid(board, row, col)) 
            {
                board[row][col] = 'Q';
                solve(board, res, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    bool valid(vector<string> &board,int row, int col){
        for(int i=0; i<row; i++){
            if(board[i][col]=='Q'){
                return false;
            } 
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            } 
        }
        for(int i=row-1, j=col+1; i>=0 && j<=board.size(); i--,j++){
            if(board[i][j]=='Q'){
                return false;
            } 
        }
        return true;
    }
};