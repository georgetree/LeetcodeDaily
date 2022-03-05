class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> t(10002,0);
        for(auto num:nums) t[num] += num;
        for(int i=2; i<10002;i++){
            t[i] = max(t[i-1],t[i-2]+t[i]);
        }
        return t[10000];
    }
};