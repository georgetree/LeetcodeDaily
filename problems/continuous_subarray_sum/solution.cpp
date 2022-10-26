class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int c = 0;
        unordered_map<int,int> m{{0,-1}}; //可以整除的情況
        for(int i=0; i<nums.size(); i++) {
            c += nums[i];
            c %= k;
            if(m.count(c)){
                if(i - m[c] >=2) return true;
            }
            else m[c] = i;
        }
        return false;
    }
};