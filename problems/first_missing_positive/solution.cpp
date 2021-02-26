class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int& num:nums){
            if(num<=0)
                num = n+1;
        }
        for(int i=0; i<n; i++){
            int t = abs(nums[i]);
            if(t <= n && nums[t-1] > 0){
                nums[t-1] *= (-1);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]>0)
                return i+1;            
        }
 
        return n+1;
    }
};