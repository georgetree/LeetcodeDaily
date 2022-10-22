class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.count(nums[i])!=1){
                m[nums[i]] = i;
            }
            else{
                int d = i - m[nums[i]];
                if(k>=d) return true; 
                if(k < d) m[nums[i]] = i; 
            }
        }
        return false;
    }
};