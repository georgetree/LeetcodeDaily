class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int n : nums){
            m[n]++;
            if(m[n] > nums.size()/2) return n; 
        }
        return {};
    }
};