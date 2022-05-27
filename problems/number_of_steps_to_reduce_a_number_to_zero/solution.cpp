class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        
        while(num){
            if(num%2) num -=1;
            else num = num>>1;
            res++;
        }
        return res;
    }
};