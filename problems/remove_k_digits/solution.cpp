class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int len = num.size()-k;
        for(auto i:num){
            while(k && !res.empty() && res.back() > i){
                res.pop_back();
                k--;
            }
            res.push_back(i);
        }
        res.resize(len);
        while(res[0] == '0') res.erase(res.begin());
        return res == "" ? "0" : res;
    }
};