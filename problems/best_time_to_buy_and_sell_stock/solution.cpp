class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int s = prices[0];
        for(int const &p:prices){
            if(p<s) s = p;
            else res = max(res,p-s);
        }
        return res;
    }
};