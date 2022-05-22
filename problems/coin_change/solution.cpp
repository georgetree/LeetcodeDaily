class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int res = 0;
        queue<int> q;
        q.push(amount);
        sort(coins.begin(),coins.end());
        vector<int> v(amount+1,0);
        v[amount] = true;
        while(!q.empty()){
            res++;
            for(int i = q.size(); i>0; i--){
                int h = q.front();
                q.pop();
                for(auto coin:coins){
                    int n = h - coin;
                    if(n==0)
                        return res;
                    else if(n<0)
                        break;
                    else if(!v[n]){
                        v[n] = true;
                        q.push(n);
                    }
                }
            }
            
        }
        return -1;
    }
};