class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combin;
        sort(candidates.begin(),candidates.end());
        cal(result,candidates,combin,0,target);
        return result;
    }
    
    void cal(vector<vector<int>> &result,vector<int>&candidates, vector<int> &combin, int start,int target){
        if(target<=0){
            if(target==0)
                result.push_back(combin);
            return;
        } 
 
        for(int i=start; i<candidates.size(); i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            combin.push_back(candidates[i]);
            cal(result,candidates,combin,i+1,target-candidates[i]);
            combin.pop_back();        
        }
    }
};