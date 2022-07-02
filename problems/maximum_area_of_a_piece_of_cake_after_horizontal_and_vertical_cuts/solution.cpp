class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mh = 0, mv = 0;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        mh = max(horizontalCuts[0], h - horizontalCuts.back());
        mv = max(verticalCuts[0], w - verticalCuts.back());
        for(int i=1; i<horizontalCuts.size(); i++){
            mh = max(mh,horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for(int i=1; i<verticalCuts.size(); i++){
            mv = max(mv,verticalCuts[i] - verticalCuts[i-1]);
        }
        
        const int MOD = 1e9 + 7;
        return ((long)mh*mv) % MOD;
    }
};