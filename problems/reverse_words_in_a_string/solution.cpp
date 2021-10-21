class Solution {
public:
    string reverseWords(string s) {
        char b;
        vector<string> temp;
        string res,t;
        for(int i=0; i<=s.length(); i++){
            b = s[i];
            if(b!=' ' && b!='\0'){
                t = t + b;
            }
            else if((b==' ' || b=='\0') && t!=""){
                temp.push_back(t);
                t="";
            }
         }
        for(int i = temp.size()-1; i>=0; i--){
            res = res + temp[i];
            if(i!=0)
                res = res  + ' ';
        }
        return res;
    }
};