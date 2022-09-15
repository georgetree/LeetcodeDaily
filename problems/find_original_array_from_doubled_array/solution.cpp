class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int len = changed.size();
        if(len%2!=0) return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int> m;
        for(auto const &c : changed)
            m[c]++;
        vector<int> res;
        for(auto c:changed){
            if(m[c]==0) continue;
            if(m[c*2]==0) return {};
            m[c]--;
            m[c*2]--;
            res.push_back(c);
        }
        return res;
    }
};