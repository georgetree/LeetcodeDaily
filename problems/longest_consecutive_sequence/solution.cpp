class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res = 0;
        for(auto num:nums){
            if(!s.count(num-1)){
                int t = 1;
   
                while(s.count(++num)) t++;
                res = max(res,t);
            } 
        }
        return res;
    }
};