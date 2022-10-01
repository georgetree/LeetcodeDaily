class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        for(int i=1; i<nums.size(); i++){
            res[i] = res[i-1]*nums[i-1];
        }
        int c = 1;
        for(int j = nums.size()-1; j>=0; j--){
            res[j] = res[j] * c;
            c *= nums[j];
        }
        return res;
    }
};