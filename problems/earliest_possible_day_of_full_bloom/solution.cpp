class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> v;
        for (auto i = 0; i < plantTime.size(); ++i)
            v.push_back({growTime[i], plantTime[i]});
        sort(v.begin(),v.end(),[](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        });
        int res = 0;
        int c = 0;
        for(auto [g,p]: v){
            c += p;
            res = max(res,c+g);
        }
        return res;
    }
};