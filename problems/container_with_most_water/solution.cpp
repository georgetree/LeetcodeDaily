class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int l = 0, r = height.size()-1;
        while(l<r){
            res = max(res,min(height[r],height[l])*(r-l));
            height[l] < height[r] ? l++ : r--;
        }
        return res;
    }
};