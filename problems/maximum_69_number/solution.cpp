class Solution {
public:
    int maximum69Number (int num) {
        int t = -1, i = 0, n = num;
        while(num>0){
        if(num%10 == 6)
           t = i;
        num/=10;
        i++;
        } 
        return t==-1 ? n : n+pow(10,t)*3;
    }
};