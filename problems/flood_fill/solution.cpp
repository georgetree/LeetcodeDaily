class Solution {
private:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size(), n = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int c = image[sr][sc];
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            image[x][y] = color;
            for(int i=0; i<4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || image[nx][ny]!=c) continue;
                q.push({nx,ny});
            }
        }
        return image;
    }
};