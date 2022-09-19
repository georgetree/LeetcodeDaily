class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> m;
        for(auto path: paths){
            stringstream ssin(path);
            string root, file, name, context;
            ssin >> root;
            while(ssin>>file){
                auto a = file.find("(");
                auto b = file.find(")");
                name = file.substr(0,a);
                context = file.substr(a+1,b);
                m[context].emplace_back(root +'/'+name );
            }
        }
        vector<vector<string>> res;
            for(auto &[k,v]:m){
                if(v.size()>1) res.push_back(v);
            }
        return res;
   
    }
};