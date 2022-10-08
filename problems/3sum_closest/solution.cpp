class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for(int i=0; i < nums.size()-2; i++){
            int l = i+1, r = nums.size()-1;
            int t = nums[i] + nums[l] + nums[r];
            while(l<r){
                t = nums[i] + nums[l] + nums[r];
                if(abs(target-t) < abs(target-res)){
                    res = t;
                }
                if(t < res) ++l; 
                else --r;
            }
        }
        return res;
    }
};