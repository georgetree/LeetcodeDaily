class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int,int> map;
        for(int a: nums1){
            for(int b: nums2)
                ++map[a+b];
        }
        
        for(int c: nums3){
            for(int d: nums4)
                res += map[-c-d];
        }
        
        return res;
    }
};