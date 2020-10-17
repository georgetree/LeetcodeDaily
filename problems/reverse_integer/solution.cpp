class Solution {
public:
    int reverse(int x) {
        int reans=0;
        while(x){
            int temp = x%10 ;   
            
            if(reans < INT_MIN/10 || reans > INT_MAX/10){
                return 0;
            }
            
            reans = temp + reans*10;
            x = x/10;
        }
        return  reans;
    }
};