class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int res = 0;
        int n = cardPoints.size();
        for(int i=0; i<k; i++) sum += cardPoints[i];
        res = sum;
        for(int i=1; i<=k; i++){
            sum = sum - cardPoints[k-i] + cardPoints[n-i];
            res = max(res,sum); 
        }
        return res;
    }
};