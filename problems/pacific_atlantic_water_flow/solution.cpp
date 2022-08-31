class Solution {
public:
    vector<vector<int>> nd{{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> res;
        vector<vector<int>> po(h.size(),vector<int>(h[0].size(),0));
        vector<vector<int>> ao(h.size(),vector<int>(h[0].size(),0));
        for(int i=0; i<h.size(); i++){
            helper(h,po,i,0);
            helper(h,ao,i,h[0].size()-1);
        }
        for(int j=0; j<h[0].size();j++){
            helper(h,po,0,j);
            helper(h,ao,h.size()-1,j);

        }
        for(int i=0; i<h.size();i++){
            for(int j=0; j<h[0].size(); j++){
                if(po[i][j] && ao[i][j])
                    res.push_back({i,j});
            }
        }
        return res;

    }
    void helper(vector<vector<int>>& h,vector<vector<int>>& v,int x,int y){
        if(v[x][y]) return;
        v[x][y] = 1;
        for(int i=0; i<4; i++){
            int nx = x + nd[i][0];
            int ny = y + nd[i][1];
            if(nx >=0 && ny < h[0].size() && nx < h.size() && ny >=0 && h[nx][ny] >= h[x][y])
                helper(h,v,nx,ny);
         }
    }
};