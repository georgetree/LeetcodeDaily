class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res{""};
        vector<string> nums = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty()) return {};
        for(int i=0; i<digits.size(); i++){
            vector<string> temp;
            for(auto j: res){
                for(auto c: nums[digits[i]-'0']){
                    temp.push_back(j+c);
                }
            }
            res = move(temp);
        }
        return res;
        
    }
};