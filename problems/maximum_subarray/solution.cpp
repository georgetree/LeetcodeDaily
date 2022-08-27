class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int k = 0;
        for(int const &num: nums){
            k = max(k+num,num);
            res = max(res,k);
        }
        return res;
    }
};