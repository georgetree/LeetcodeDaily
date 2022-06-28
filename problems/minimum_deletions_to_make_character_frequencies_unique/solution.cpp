class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        int count = s.size();
        int res = 0;
        for(char i:s) v[i-'a']++;
        sort(v.begin(),v.end(),greater<int>());
        for(auto it = v.begin(); it!=v.end() && *it>0; it++){
            count = min(count,*it);
            res += *it - count;
            if(count>0) count --;
        }
        return res;
    }
};
