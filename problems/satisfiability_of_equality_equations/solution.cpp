class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> v(26);
        for(int i=0; i<26; i++) v[i] = i;
        for(auto &e :equations){
            if(e[1]=='!') continue;
            v[find(v,e[0]-'a')] = find(v,e[3]-'a'); 
        }
        for(auto &e :equations){
            if(e[1]=='=') continue;
            if(v[find(v,e[0]-'a')] == find(v,e[3]-'a')) return false;
        }
        return true;
    }
    int find(vector<int> &r, int x){
        return r[x] == x ? x : r[x] = find(r,r[x]);
    }
};