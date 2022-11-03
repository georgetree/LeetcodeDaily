class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = (r-l)/2+l;
            if(nums[mid] > target) r = mid-1;
            else if(nums[mid] < target) l = mid+1;
            else return mid;
        }
        return -1;
    }
};