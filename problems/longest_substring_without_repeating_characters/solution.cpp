class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char>st;
        int n = s.size();
        for(int i=0, j=0;  i<n && j<n; ){
            if(st.find(s[i]) == st.end()){
                st.emplace(s[i++]);
                res = max(res, i-j);
            }
            else
                st.erase(s[j++]);
        }
        return res;
    }
};