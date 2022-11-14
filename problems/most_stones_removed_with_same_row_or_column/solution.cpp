class Union{

public:
 
    vector<int> v;

    Union(int n): v(n){
        for(int i=0; i<n; i++) v[i] = i;
    }
    int find(int i){
        return v[i] == i ? i : v[i] = find(v[i]);
    }
    void connect(int g1,int g2){
        v[find(g1)] = find(g2);
    }

};
class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        Union u(10000*2);
        for(int i=0; i<n; i++){
            u.connect(stones[i][0]+10000,stones[i][1]);
        }
        unordered_set<int> seen;
        for(auto &s:stones){
            seen.insert(u.find(s[1]));
        }
        return n - seen.size();
    }
};