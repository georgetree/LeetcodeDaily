class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 0;
        for(auto i: nums){
            if(res < 2 || i > nums[res-2])
                nums[res++] = i;
        }
        return res;
    }
};