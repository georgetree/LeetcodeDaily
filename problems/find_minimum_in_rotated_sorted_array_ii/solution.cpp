class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r){
            int p = (l + r) / 2;
            if(nums[p] < nums[r])
                r = p;
            else if(nums[p] > nums[r])
                l = p+1;
            else
                r -=1;
        }
        return nums[l];
    }
};