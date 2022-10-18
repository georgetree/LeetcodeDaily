class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for(int i=1; i<n; i++){
            string cur = "";
            for(int j=0; j < res.size(); j++){
                int cnt = 1;
                while(j < res.size() && res[j] == res[j+1]){
                    cnt++;
                    j++;
                }
                cur += to_string(cnt) + res[j];
            }
            res = cur;
        }
        return res;
    }
};