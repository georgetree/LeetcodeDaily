class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combin;
        helper(candidates, target, combin, res,0);
        return res;
    }
    
    void helper(vector<int>& candidates, int t, vector<int>& combin, vector<vector<int>>& res, int s){
        if(t==0){
            res.push_back(combin);
            return;
        }else if(t<0)
            return;
        for(int i=s; i<candidates.size(); i++){
            combin.push_back(candidates[i]);
            helper(candidates, t-candidates[i], combin, res, i);
            combin.pop_back();
        }
    }
};