class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0; i<mat.size();i++){
            for(int j=0; j<mat[0].size();j++){
                if(mat[i][j] == 0){
                    q.push(make_pair(j,i));
                    break;
                }
                if(j==mat[0].size()-1 && j!=0){
                    q.push(make_pair(mat[0].size(),i));
                }
            }
        }
        for(int i=0; i<k; i++){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};