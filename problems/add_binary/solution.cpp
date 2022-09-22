class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size()-1;
        int n = b.size()-1;
        string res = "";
        int carry = 0;
        while(m>=0 || n>=0){
            int tempA = m >= 0 ? a[m--] - '0': 0;
            int tempB = n >= 0 ? b[n--] - '0': 0;
            int sum = tempA + tempB + carry;
            res = to_string(sum%2) + res;
            carry = sum/2;
        }
        return carry !=0 ? '1'+res : res;
    }
};