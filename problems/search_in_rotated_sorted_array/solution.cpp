class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r=nums.size()-1;
        while(l<=r){
            int mid = (r-l)/2+l;
            if(target==nums[mid]) return mid;
            else if(nums[mid] < nums[r]){
                if(target > nums[mid] && nums[r] >= target) l = mid+1;
                else r = mid-1;
            }
            else{
                if(target < nums[mid] && nums[l] <= target) r = mid-1;
                else l = mid+1;
            }
        }
        return -1;
    }
};