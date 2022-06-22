class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> se(nums.begin(),nums.end());
         
        return *(next(se.rbegin(), k-1));
    }
};