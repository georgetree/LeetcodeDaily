class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        using Pair = pair<int,int>;
        int n = grid.size();
        queue<Pair> q;
        //set<Pair> visited;
        int res = 0;
        q.push({0,0});
        //visited.insert({0,0});
        vector<Pair> dirs{{0,1},{1,0},{1,1},{0,-1},{-1,-1},{-1,0},{-1,1},{1,-1}};
        while(!q.empty()){
            ++res;
            for(int i=q.size(); i>0; i--){
                auto [x,y] = q.front();
                q.pop();
                if(x == n-1 && y == n-1) return res;
                for(auto [dirX,dirY] : dirs){
                    int newX = x+dirX, newY = y+dirY;
                    if(newX < 0 || newX >= n || newY < 0 || newY >= n || grid[newX][newY]==1)
                        continue;
                    if(grid[newX][newY]==0){
                        grid[newX][newY] = 1;
                        q.push({newX,newY});
                    }
                        
                }
            }
        }
        return -1;
    }
};