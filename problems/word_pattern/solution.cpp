class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream is(s);  
        string st;  
        vector<string> temp;
        while(is>>st) temp.push_back(st);
        if(temp.size() != pattern.size()) return false;
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        for(int i=0; i<pattern.size(); i++){
            if(m1.find(pattern[i]) == m1.end() && m2.find(temp[i]) == m2.end()){
                m1[pattern[i]] = temp[i];
                m2[temp[i]] = pattern[i];
                continue;
            }
            else if(m1[pattern[i]] != temp[i]) 
                return false;
        }
        return true;
    }
};