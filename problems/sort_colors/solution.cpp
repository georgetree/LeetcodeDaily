class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = nums.size()-1;
        int l = 0;
        int i = 0;
        while(i<=r){
            if(nums[i]==0) swap(nums[i++],nums[l++]);
            else if(nums[i]==1) i++;
            else swap(nums[i],nums[r--]);
        }
    }
};