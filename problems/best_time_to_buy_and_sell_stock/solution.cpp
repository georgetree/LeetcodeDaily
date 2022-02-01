class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t = prices[0];
        int res = 0;
        for(auto &i: prices){
            if(t > i)
                t = i;
            else if(t < i)
               res = max(res,i-t);
        }
        return res;
    }
};