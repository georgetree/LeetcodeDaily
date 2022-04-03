class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        int n = nums.size();
        for(i = n-2; i>=0; --i){
            if(nums[i+1] > nums[i]){
                for(j = n-1; j>i; --j){
                    if(nums[i] < nums[j]) break;
                }
                swap(nums[i],nums[j]);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
        }
        reverse(nums.begin(),nums.end());
         
    }
};