class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> numlist;
        combinSum(res,numlist,k,n,1);
        return res;
    }
    void combinSum(vector<vector<int>> &res,vector<int> &numlist, int k, int n, int start){
        if(numlist.size()==k || n<=0){ 
            if(numlist.size()==k && n==0){
                res.push_back(numlist);
            }
            return;
        }
        for(int i=start; i<=9; i++){
            numlist.push_back(i);
            combinSum(res,numlist,k,n-i,i+1);
            numlist.pop_back();
        }
    }
};