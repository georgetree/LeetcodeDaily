class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1 ;
        int maxarea=0;
        while(l<r){
            maxarea = max(maxarea,(r-l)*min(height[l],height[r]));
            height[l] <= height[r] ? ++l : --r;
        }
        return maxarea;
    }
};