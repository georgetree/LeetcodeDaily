class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int la = a.size()-1;
        int lb = b.size()-1;
        int c = 0;
        while(la >= 0 || lb >= 0){
            int t1 = la >= 0 ? a[la--] - '0' : 0; 
            int t2 = lb >= 0 ? b[lb--] - '0' : 0;
            int sum = t1 + t2 + c ;
            res = to_string(sum%2) + res ;
            c = sum / 2;
        }
        return c > 0 ? '1'+res : res;
    }
};