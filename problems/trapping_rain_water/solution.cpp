class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n);
        vector<int> r(n);
        int res = 0;
        for(int i=0; i<n; i++){
            l[i] = i==0 ? height[i] : max(height[i],l[i-1]);
        }
        for(int j=n-1; j>=0; j--)
            r[j] = j==n-1 ? height[n-1] : max(height[j], r[j+1]);
        for(int i=0; i<n; i++){
            res += min(l[i],r[i]) - height[i];
        }
        return res;
    }
};