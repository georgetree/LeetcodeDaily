class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0, pre = 0;
        for (auto x:nums) {
            pre += x;
            if (m.find(pre - k) != m.end()) {
                res += m[pre - k];
            }
            m[pre]++;
        }
        return res;
    }
};