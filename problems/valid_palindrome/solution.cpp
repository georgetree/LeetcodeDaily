class Solution {
private:
    bool isValid(char c){
        return (c >= 'a' && c <= 'z') || (c>='A' && c<='Z') || (c>='0' && c<= '9');
    }
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<=r){
            if(!isValid(s[l])) {
                l++;
                continue;
            }
            if(!isValid(s[r])){
                r--;
                continue;
            } 
            if(tolower(s[l]) == tolower(s[r])){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
};