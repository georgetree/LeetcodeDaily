class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n] ;
        dp[0] = 1;
        int p1=0,p2=0,p3=0;
        for(int i=1; i<n; i++){
           int temp = min(dp[p1]*2 , min(dp[p2]*3 , dp[p3]*5));
            if(temp==2*dp[p1])
                p1++;
            if(temp==3*dp[p2])
                p2++;
            if(temp==5*dp[p3])
                p3++;
        dp[i] = temp ;
        }
        return dp[n-1];
    }
};