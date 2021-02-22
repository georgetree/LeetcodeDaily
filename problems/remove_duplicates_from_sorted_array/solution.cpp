class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=1; 
        if(nums.empty())
            return 0;
        for(int i=1; i<nums.size(); i++ ){
             if(nums[i-1]!=nums[i]){
                nums[c++]=nums[i];
             }
         }
        return c;
    }
};