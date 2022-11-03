class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(auto c: t) m[c]++;
        string res = "";
        int count = 0;
        int len = INT_MAX;
        int l = 0;
        int minStart = 0;
        for(int i=0; i<s.size(); i++){
            if(m.count(s[i])){
                if(--m[s[i]] >= 0) count++;
            }
            while(count == t.size()){
                if(len > i-l+1){
                    len = i-l+1;
                    minStart = l;
                }
                if(m.count(s[l])){
                    if(++m[s[l]] > 0) count --;
                }
                l++;
            }
        }
        return len == INT_MAX ? "" : s.substr(minStart,len);
    }
};