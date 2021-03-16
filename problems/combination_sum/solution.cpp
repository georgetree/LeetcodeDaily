class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    
        vector<vector<int>> result;
        vector<int> combin;
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
            combin.push_back(candidates[i]);
            cal(result,candidates,combin,i,target-candidates[i]);
            combin.pop_back();        
        }
    }
};