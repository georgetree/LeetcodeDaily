class Trie {
public:
    string word;
    Trie *node[26]; 
};

class Solution {
public:
    vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
    Trie* buildTrie(vector<string>& words){
        Trie* root = new Trie();
        for(auto wd:words){
            Trie* cur = root;
            for(auto w:wd){
                if(!cur->node[w-'a']) cur->node[w-'a'] = new Trie();
                cur = cur->node[w-'a'];    
            }
            cur->word = wd;
        }
        return root;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie* root = buildTrie(words);
   
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(root->node[board[i][j] - 'a']!=nullptr)
                    helper(board,res,root->node[board[i][j] - 'a'],i,j);
            }
        }
        return res;
    }
    void helper(vector<vector<char>>& board, vector<string>& res, Trie* root,int x,int y){
    
        if(!root->word.empty()){
            res.push_back(root->word);
            root->word.clear();
       
        }
        char c = board[x][y];
        board[x][y] = '#';
        for(auto &d:dir){
            int nx = x+d[0];
            int ny = y+d[1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] != '#' && root->node[board[nx][ny]-'a'] )
                helper(board,res,root->node[board[nx][ny]-'a'],nx,ny);
        }
        board[x][y] = c;
    }
};