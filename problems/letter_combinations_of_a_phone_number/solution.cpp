class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res{""};
        if(digits=="") return {};
        vector<string> m = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0; i<digits.size();i++){
            vector<string> t;
            for(auto j:res){
                for(auto d:m[digits[i]-'0']){
                    t.push_back(j+d);
                }
            }
            res = t;
        }
        return res;
    }
};