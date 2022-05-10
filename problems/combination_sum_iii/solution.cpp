class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> res;
        vector<int> combin;
        helper(res,combin,k,n,1);
        return res;
    }
    
    void helper(vector<vector<int>> &res, vector<int> &combin,int k, int n, int start){
        if(n<=0 || combin.size()==k){
            if(n==0 && combin.size()==k)
                res.push_back(combin);
            return;
        }
        for(int i=start; i<=9; i++){
            combin.push_back(i);
            helper(res,combin,k,n-i,i+1);
            combin.pop_back();
        }
    }
};