class Solution {
public:
    bool isPowerOfThree(int n) {
        auto t = pow(3, floor(log(INT_MAX)/log(3)));
 
        return n>0 && (int)t%n==0;
    }
};