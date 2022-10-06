class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(n,k,temp,res,1);
        return res;
    }
    
    void helper(int n, int k, vector<int> &temp , vector<vector<int>> &res, int s){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=s; i<=n; i++){
            temp.push_back(i);
            helper(n,k,temp,res,i+1);
            temp.pop_back();
        }
    }
};