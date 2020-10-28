class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        sort(coins.rbegin(),coins.rend());
        int ans = INT_MAX;
        coinCh(coins,amount,ans,0,0);
        return ans == INT_MAX ? -1 : ans ;
    }
    
    
    void coinCh(vector<int>& coins, int amount, int& ans, int coin_index, int count){
        if(amount==0){
            ans = min(ans,count);
            return ;
        }
        if(coin_index == coins.size()) return ;
        for(int i = amount/coins[coin_index]; i>=0 && i+count <= ans; --i){
            coinCh(coins, amount-(i*coins[coin_index]), ans, coin_index+1, count+i);
        }
    }
};

     