class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> com;
        dfs(result,com,n,k,1);
        return result;
    }
    void dfs(vector<vector<int>> &result, vector<int> &com,  int n, int k, int start){
        if(com.size()==k){ 
            result.push_back(com);
            return;
        }
        for(int i=start; i <= n; i++){
            com.push_back(i);
            dfs(result,com,n,k,i+1);
            com.pop_back();
        }
    }
};