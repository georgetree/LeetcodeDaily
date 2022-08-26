class Solution {
public:
    vector<vector<int>> dr{{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        helper(image,sr,sc,newColor);
        return image;
    }
    void helper(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(image[sr][sc]==newColor) return;
        int t = image[sr][sc];
        image[sr][sc] = newColor;
        for(int i=0; i<4; i++){
            int newx = sr + dr[i][0];
            int newy = sc + dr[i][1];
            if( newx>=0 && newx<image.size() && newy>=0 && newy<image[0].size()){
                if( image[newx][newy] == t)
                    helper(image,newx,newy,newColor);
            }
        }
        
    }
};