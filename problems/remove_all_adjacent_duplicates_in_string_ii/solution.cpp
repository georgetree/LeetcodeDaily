class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int,char>> st;
        for(auto i:s){
            if(st.empty() || i != st.back().second)
                st.push_back({1,i});
            else if(++st.back().first == k){
                st.pop_back();
            }
        }
        string res = "";
        for(auto a:st){
            res.append(a.first,a.second);
        }
            
        return res;
    }
};