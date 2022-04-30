class UnionFind {
    private:
        vector<int> root;
        vector<double> weights;
    public:
        UnionFind(int n): root(n), weights(n,1.0){
            iota(root.begin(),root.end(),0);
        }
        int find(int i){
            if(root[i]!=i){
                int t = root[i];
                root[i] = find(root[i]);
                weights[i] *= weights[t];
            }
            return root[i];
        }
        double isConnected(int x, int y){
            if(find(x)==find(y))
                return weights[x]/weights[y];
            else return -1.0;
        }
        void doUnion(int x, int y, double value){
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY) return;
            root[rootX] = rootY;
            weights[rootX] = weights[y] * value / weights[x];
        }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int size = equations.size();
        UnionFind unionFind(2*size);
        unordered_map<string,int>m;
        int n = 0;
        for(int i=0 ; i<size; i++){
            for(int j=0; j<2; j++){
                string t = equations[i][j];
                if(!m.count(t)){
                    m[t] = n++;
                }
            }
            unionFind.doUnion(m[equations[i][0]],m[equations[i][1]], values[i]);
        }
        int queriesSize = queries.size();
        vector<double> res(queriesSize, -1.0);
        for(int i=0; i<queriesSize; i++){
            string t1 = queries[i][0];
            string t2 = queries[i][1];
            if(m.count(t1) && m.count(t2)){
                res[i] = unionFind.isConnected(m[t1],m[t2]);
            }
        }
        return res;
    }
};