class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size()-1;
        int res = 0;
        for(auto i: columnTitle){
            res += (i-64)*pow(26,n);
            n--;
        }
        return res;    
    }
    
};