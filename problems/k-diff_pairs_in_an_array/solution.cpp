class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0; 
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        for(auto j:m){
            if(k==0 && j.second>1) res++;
            if(k>=1 && m.count(j.first+k)) res++;
            
        }
        return res;
    }
};