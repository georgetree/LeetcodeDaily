class Solution {
public:
    int find(vector<int> &root, int i){
        return root[i] == i ? i : find(root,root[i]);
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> root(graph.size());
        for(int i=0; i<graph.size(); i++)
            root[i] = i;
        for(int i=0; i<graph.size(); i++){
            if(graph[i].empty()) continue;
            int x = find(root,i);
            for(int j = 0; j<graph[i].size(); j++){
                int t = find(root,graph[i][j]);
                if(x == t) return false;
                root[find(root,graph[i][0])] = t;
            }
        }
        return true;
    }
    
};