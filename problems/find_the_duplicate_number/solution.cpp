class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;
        while(true){
            s = nums[s];
            f = nums[nums[f]];
            if(s==f) break;
        }
        int t=0;
        while(true){
            s = nums[s];
            t = nums[t];
            if(s==t) break;
        }
        return s;
    }
};