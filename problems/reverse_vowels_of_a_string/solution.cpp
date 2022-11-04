class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r= s.size()-1;
        unordered_set<char> st({'a', 'e', 'i', 'o','u'});
        while(l<r){
            if(st.count(tolower(s[l]))!=1) {
                l++;
                continue;
            }
            if(st.count(tolower(s[r]))!=1) {
                r--;
                continue;
            }
            swap(s[r],s[l]);
            l++;
            r--;
        }
        return s;
    }
};