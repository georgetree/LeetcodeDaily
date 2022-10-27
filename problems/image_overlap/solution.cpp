class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res = 0;
        vector<vector<int>> ig2,ig1;
        unordered_map<string,int> m;
        for(int i=0; i<img2.size(); i++){
            for(int j=0; j<img2.size(); j++){
                if(img2[i][j]==1) ig2.push_back({i,j});
                if(img1[i][j]==1) ig1.push_back({i,j});
            }
        }
        for (auto a : ig1) {
            for (auto b : ig2) {
                ++m[to_string(a[0] - b[0]) + "-" + to_string(a[1] - b[1])];
            }
        }
        for(auto i:m){
            res = max(res,i.second);
        }
        return res;
    }
};