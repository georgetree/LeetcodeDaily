class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m = nums[0], n = INT_MAX;
        for(int &num :nums){
            if(m>= num) m = num;
            else if(n >= num) n = num;
            else return true;
        }
        return false;
    }
};