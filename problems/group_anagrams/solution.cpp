class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> m;
        vector<vector<string>> res;
        for(auto str: strs){
            string temp = str;
            sort(str.begin(),str.end());
            if(!m.count(str)){
                m[str] = res.size();
                res.push_back({});
            }
            res[m[str]].push_back(temp);
        }
        return res;
    }
};