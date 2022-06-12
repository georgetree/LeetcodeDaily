class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int res = 0, count = 1, n=nums.size(), l = -1;
        vector<int> prefix(n+1,0);
        prefix[0]=nums[0];
 
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
            if(m.count(nums[i])>0 && l < m[nums[i]]){
                l = m[nums[i]];
            }
            m[nums[i]] = i;
            
            res = max(res,prefix[i+1] - prefix[l+1]);
        }
        return res;
        
    }
};