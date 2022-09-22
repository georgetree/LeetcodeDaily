class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, sum = 0;
        for(int &n:nums){
            sum = max(sum+n,n);
            res = max(res,sum);
        }
        return res;
    }
};