class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int count = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(count > prices[i]) count = prices[i];
            res = max(res,prices[i] - count);
        }
        return res;
    }
};