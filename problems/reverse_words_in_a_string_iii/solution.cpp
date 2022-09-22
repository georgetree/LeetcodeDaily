class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp = "";
        istringstream ss(s);
        while(ss>>temp){
            reverse(temp.begin(),temp.end());
            res += temp + " ";
        }
        res.pop_back();
        return res;
    }
};