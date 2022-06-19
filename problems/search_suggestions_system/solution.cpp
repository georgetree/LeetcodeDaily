class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        string q = "";
        auto it = products.begin();
        sort(products.begin(),products.end());
        for(auto i:searchWord){
            vector<string> t;
            q +=i;
            it = lower_bound(it,products.end(),q);
            for(int j=0; j<3 && (it+j)!=products.end(); j++){
                string temp = *(it+j);
                if(temp.substr(0,q.size())!=q) break;
                t.push_back(temp);
            }
            res.push_back(t);
        }
        return res;
    }
};