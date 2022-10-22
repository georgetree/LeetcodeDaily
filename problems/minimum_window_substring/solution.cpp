class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for(auto s:t) m[s]++;
        string res = "";
        int count = 0;
        int left = 0;
        int len = INT_MAX;
        for(int i=0; i<s.size(); i++){
            if(--m[s[i]] >= 0) ++count;
            while(count==t.size()){
                if(len > i-left+1){
                    len = i-left+1;
                    res = s.substr(left,len);
                }
                if(++m[s[left]]>0) --count;
                ++left;
            }
        }
        return res;
    }
};