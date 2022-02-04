class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m = {{0,-1}};
        int res = 0, cur = 0;
        for(int i=0; i < nums.size(); i++){
            nums[i] == 0 ? --cur : ++cur;
            if(m.count(cur))
                res = max(res, i-m[cur]);
            else
                m[cur] = i;
        }
        return res;
    }
};