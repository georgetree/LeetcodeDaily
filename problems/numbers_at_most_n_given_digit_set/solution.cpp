class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string l = to_string(n);
        int len = l.length();
        int res = 0;
        
        for(int i=1; i<len; i++){
            res += pow(digits.size(),i);
        }
        
        for(int i=0; i<len; i++){
            bool flag = false; 
            for(auto &s : digits ){
                if(s[0] < l[i])
                   res += pow(digits.size(),len-1-i);
                else if(s[0] == l[i]){
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return res;
        }
        return res+=1;
    }
};