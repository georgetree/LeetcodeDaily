class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto &w:words){
            m[w]++;
        }
        vector<string> res;
        auto cmp = [](const pair<string,int> &p1, const pair<string,int> &p2) {
            if(p1.second == p2.second)
                return p1.first > p2.first;
            return p1.second < p2.second;
        };

        priority_queue<pair<string,int>,vector<pair<string,int> >,decltype(cmp)> q(cmp);
        
        for(auto [k,v]: m){
              q.push({k,v});  
        }
        for(int i=0; i<k; i++){
            res.push_back(q.top().first);
            q.pop();
        }
            
        return res;
    }
};