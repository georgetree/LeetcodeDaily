class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> m;
        stack<char> st;
        string res="";
        for(auto i:s)
            m[i]++;
        for(auto i:s){
            m[i]--;
            if(res.find(i) != string::npos ) continue; //res裡已經有了，不需要再加入
            while( m[res.back()]>0 && res!="" && res.back() > i)
                res.pop_back();
            res.push_back(i);
        }
        return res;
    }
};