class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> b;
        for(int i=0; i<buildings.size(); i++){
            b.push_back({buildings[i][0],-buildings[i][2]});
            b.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(b.begin(),b.end());
        multiset<int> m;
        m.insert(0);
        vector<vector<int>> res;
        int prehight = 0;
        for(auto &i: b){
            if(i[1] < 0)
                m.emplace(-i[1]);
            else{
                m.erase(m.find(i[1])); //向下移動 i[1]代表是曾經橫向端點的終點 所以移除
            }
            if(prehight != *m.rbegin()){
                prehight = *m.rbegin();
                res.push_back({i[0],prehight});
            }
        }
        return res;
    }
};