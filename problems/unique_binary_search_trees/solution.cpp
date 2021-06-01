class Solution {
public:
    int numTrees(int n) {
        double a = static_cast<double>(1.0/(n+1));
         
        return  round(a*(ft(2*n)/(ft(n)*ft(n))));
    }
    double ft(int n){
        return (n==1||n==0) ? 1 : ft(n-1)*n;
    }
};