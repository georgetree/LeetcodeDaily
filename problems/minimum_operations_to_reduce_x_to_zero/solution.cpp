class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto i:nums) sum+=i;
        int l = 0, r = 0, n = nums.size(), tempSum = 0, res=-1;
        int target = sum-x;
        while(r<n){
            tempSum += nums[r++];
            while(tempSum > target && l<n){
                tempSum -= nums[l++];
            }
            if(tempSum == target)
                res = max(res,r-l);
        }
        return res == -1 ? -1 : n-res;
    }
};