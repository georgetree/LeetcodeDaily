class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        bt(res, s, temp, 0);
        return res;
    }
    
    void bt(vector<vector<string>> &res, string s, vector<string> &temp, int start){
        if(s.size()==start) {
            res.push_back(temp); 
            return;
        }    
        for(int i=start; i<s.size();i++){
            if(!isPalindrome(s,start,i)) continue;
            temp.push_back(s.substr(start,i - start + 1));
            bt(res, s, temp, i+1);
            temp.pop_back();
        }
    }
    
    bool isPalindrome(string s, int start, int end ){
        while(start<end)
            if(s[start++]!=s[end--]) return false;
        return true;
    } 
};