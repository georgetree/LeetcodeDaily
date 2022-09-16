class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& m) {
        int res = INT_MIN;
        int n = nums.size();
        int len = m.size();
        vector<vector<int>> dp(len+1,vector<int>(len+1,0));
        for(int i=1; i<=len; i++){
            for(int j=0; j<=i; j++){
                int k = i-j;
                int left = (j == 0 ? INT_MIN : dp[j-1][k] + m[i-1]*nums[j-1]);
                int right = (j == i ? INT_MIN : dp[j][k-1] + m[i-1]*nums[n-k]);
                dp[j][k] = max(right,left);
                
                if(i==len) res = max(res,dp[j][k]);
            }
         
        }
        return res;
    }
};