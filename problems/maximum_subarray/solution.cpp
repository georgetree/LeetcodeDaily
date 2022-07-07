class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int cur = 0;
        for(auto num:nums){
            cur = max(num+cur,num);
            res = max(cur,res);
     
        }
        return res;
    }
};