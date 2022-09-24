class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<len; i++){
            if(nums[i]>0) return res;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1, r = len-1;
            while(l<r){
                if((nums[i]+nums[l]+nums[r])==0){
                    vector<int> t{nums[i],nums[l],nums[r]};
                    res.push_back(t);
                    while(l<r && nums[l]==nums[l+1]) ++l;
                    while(l<r && nums[r]==nums[r-1]) --r;
                    ++l;
                    --r;
                }
                else if((nums[i]+nums[l]+nums[r])>0) --r;
                else ++l;
            }
        }
        return res;
    }
};