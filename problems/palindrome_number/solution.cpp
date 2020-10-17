class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int count{};
        stack<int> palstack;
        int temp;
        temp = x;
        while(x){
            x/=10;
            count++;
        }
        for(int i=0;i<count/2;++i){
            palstack.push(temp%10);
            temp/=10;
        }
        if(count%2==1){
            temp/=10;
        }
        for(int i=0;i<count/2;++i){
            int val = palstack.top();
            if(val!=temp%10) return false;
            temp/=10;
            palstack.pop();
        }
        return true;
     }
};