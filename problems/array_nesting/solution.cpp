class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res=0;
        for(auto i:nums){
            int count = 1;
            while(nums[i]!=i){
                count++;
                swap(nums[i],nums[nums[i]]);
            }
            res = max(count,res);
        }
        return res;
        
    }
};