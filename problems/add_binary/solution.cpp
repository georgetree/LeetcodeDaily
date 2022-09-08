class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size()-1, n = b.size()-1;
        int c = 0;
        string res = "";
        while(m>=0 || n>=0){
            int l = m>=0 ? a[m--] - '0' : 0;
            int r = n>=0 ? b[n--] - '0' : 0;
            int sum = l+r+c;
            res = to_string(sum%2) + res;
            c = sum/2;
        }
        return c>0 ? "1" + res : res;
    }
};