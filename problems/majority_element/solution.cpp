class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(res == nums[i])
                count++;
            else if(count > 0)
                count --;
            else{
                res = nums[i];
            }
                
        }
        return res;
    }
};