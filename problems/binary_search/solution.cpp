class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0;
        int t = 0;
        int s = 0, e = nums.size()-1;
        while(s<=e){
            t = s+(e-s)/2;
            res = nums[t];
            if(res == target)
                return t;
            else if(res > target)
                e = t-1;
            else if(res < target)
                s = t+1;
        }
        return -1;
    }
};