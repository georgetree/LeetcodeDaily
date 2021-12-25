class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        int res = 0, n=0, tn;
        char temp;
        while(in >> temp >> n){
            if(temp == '+' || temp == '-'){
                n = temp=='+'? n : -n;
                res +=n;
            }
            else{
                n = temp=='*' ? tn*n : tn/n;
                res = res - tn + n;
            }
            tn = n;
        }
        return res;
    }
};