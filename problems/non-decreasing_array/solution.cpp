class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() == 1)   return true;
        bool m = nums[0] <= nums[1] ? true : false;  

        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(m){
                    m = false;
                    if(nums[i+1] >= nums[i-1]){
                        nums[i] = nums[i+1];
                    }
                    else nums[i+1] = nums[i];
                }
                else return false;
            }
            
        }
        return true;
    }
};