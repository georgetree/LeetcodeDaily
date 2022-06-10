class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int tempColor = image[sr][sc];
        if(tempColor != newColor) 
            helper(image,sr,sc,tempColor,newColor);
        return image;   
    }
    void helper(vector<vector<int>>& image, int x, int y,int tempColor, int newColor){
        if(image[x][y] == tempColor){
            image[x][y] = newColor;
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<image.size() && ny<image[0].size())
                    helper(image,nx,ny,tempColor,newColor);
            }
        }
        
    }
};