class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res,n,n,"");
        return res;
    }
    
    void helper(vector<string> &res, int l, int r, string s){
        if(l==0 && r==0){
            res.push_back(s);
            return;
        }
        
        if(l>0) helper(res,l-1,r,s+"(");
        if(r>l) helper(res,l,r-1,s+")");
        
    }
};