class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        q.emplace_back(nums[0],0);
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            while(i - q.front().second > k)
                q.pop_front();
            res = nums[i] + q.front().first;
            while(!q.empty() && res >= q.back().first) q.pop_back();
            q.emplace_back(res,i);
        }
        return res;
    }
};