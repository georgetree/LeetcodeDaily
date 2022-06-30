class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size()/2;
        nth_element(nums.begin(), nums.begin() + n, nums.end());
        int res = 0;
        for(auto num:nums){
            res += abs(nums[n] - num); 
        }
        return res;
    }
};