class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<3 || nums.front() > 0 || nums.back() < 0) return{};
        vector<vector<int>> res;

        for(int k=0; k<nums.size()-2; k++){
            if(k > 0 && nums[k]==nums[k-1]) continue; 
            int i = k+1, j = nums.size()-1;
            while(i<j){
                if((nums[i]+nums[j]+nums[k]) == 0){
                    vector<int> t{nums[k],nums[i],nums[j]};
                    res.push_back(t);
                    while(i<j && nums[i]==nums[i+1]) ++i;
                    while(i<j &&nums[j]==nums[j-1]) --j;
                    ++i,--j;
                }
                else if(nums[i]+nums[j]+nums[k]>0) j--;
                else i++;
            }
        }
        return res;
        }
};