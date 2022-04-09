class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m; 
        priority_queue<pair<int,int>> q;
        for(auto i: nums)
            m[i]++;
        for(auto i: m)
            q.push(make_pair(i.second,i.first));
        
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};