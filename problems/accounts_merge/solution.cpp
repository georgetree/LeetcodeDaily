class Solution {
public:
    string find(string i,unordered_map<string, string>& root){
        return root[i] == i ? i : root[i] = find(root[i],root);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> root;
        unordered_map<string, string> owner;
        for(auto acc:accounts){
            for(int j=1; j<acc.size(); j++){
                root[acc[j]] = acc[j];
                owner[acc[j]] = acc[0];
            }
        }
        for(auto acc:accounts){
            string p = find(acc[1], root);
            for(int j=2; j<acc.size(); j++){
                root[find(acc[j],root)] = p;  
            }
        }
        unordered_map<string, set<string>> m;
        for (auto acc : accounts) {
            for (int i = 1; i < acc.size(); ++i) {
                m[find(acc[i], root)].insert(acc[i]);
            }
        }
        vector<vector<string>> res;
        for(auto [k,v]: m){
            vector<string> temp(v.begin(),v.end());
            temp.insert(temp.begin(), owner[k]);
            res.push_back(temp);
        }
        return res;
    }
};