class Solution {
public:
     
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        vector<int> res;
        
        for(auto &i:envelopes){
            auto iter = lower_bound(res.begin(),res.end(),i[1]);
            if(iter == res.end())
                res.push_back(i[1]);
            else               
                *iter = i[1];
        }
    
        return res.size();
    }
};