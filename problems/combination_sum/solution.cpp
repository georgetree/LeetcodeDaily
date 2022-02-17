class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(candidates,target,tmp,res,0);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int> &tmp, vector<vector<int>> &res, int start){
        if(target<=0){
            if(target==0)
                res.push_back(tmp);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            tmp.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],tmp,res,i);
            tmp.pop_back();
        }
    }
};