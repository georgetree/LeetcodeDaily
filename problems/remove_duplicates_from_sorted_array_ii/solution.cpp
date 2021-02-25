class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 0;
        for (int e : nums){
            if(c < 2 || e>nums[c-2])
                nums[c++] = e;
        }
        return c;
    }
};