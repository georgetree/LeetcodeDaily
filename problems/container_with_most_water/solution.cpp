class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; 
        int r = height.size()-1;
        int maxarea{};
        while(l<r){
            maxarea = max(maxarea,(r-l)*min(height[l],height[r]));
            height[l]<=height[r] ? ++l : --r ;
            // if(height[l]<=height[r]){
            //     int temp = (r-l)*height[l];
            //     maxarea = max(maxarea,temp);
            //     l++;
            // }
            // else{
            //     int temp = (r-l)*height[r];
            //     maxarea = max(maxarea,temp);
            //     r--;
            // }
        }
        return maxarea;
    }
};