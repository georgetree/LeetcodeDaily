class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (helper(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, string word, int x,int y,int count){
        if(count == word.size()) return true;
        if(x<0|| x>=board.size()|| y<0 || y>=board[0].size() || board[x][y]!=word[count]) return false;
        char temp = board[x][y];
        // count++;
        board[x][y] = '#';
        bool res = helper(board,word,x + 1,y + 0,count+1)
            || helper(board,word,x + 0,y + 1,count+1)
            || helper(board,word,x - 1,y + 0,count+1)
            || helper(board,word,x + 0,y - 1,count+1);
        board[x][y] = temp;
        return res;
    }
};