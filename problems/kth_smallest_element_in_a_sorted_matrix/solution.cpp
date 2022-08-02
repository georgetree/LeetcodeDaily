class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for(auto const &i:matrix){
            for(auto const &j:i){
                q.emplace(j);
                if(q.size()>k) q.pop();
            }
        }
        return q.top();
    }
};