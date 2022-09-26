class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> v(2001);
        for(int i=0; i<2001; i++) v[i] = i;
        for(auto &edge :edges){
            int x = Find(v,edge[0]);
            int y = Find(v,edge[1]);
            if(x == y) return edge;
            v[x] = y;
        }
        return {};
    }
    int Find(vector<int> &v, int i){
        return v[i] == i ? i : v[i] = Find(v,v[i]);
    }
  
};