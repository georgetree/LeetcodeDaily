class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        auto r =  log(n)/log(4);
        return r==(int)r ? true : false;
    }
};