class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        int res = 0;
        for(auto w:words){
            string temp = w;
            reverse(w.begin(),w.end());
            if(m[w]>0){
                res += 4;
                --m[w];
            }
            else{
                ++m[temp];
            }
        }
        
        for(auto [k,v]:m){
            if(k[0]==k[1] && m[k]>0){
                res+=2;
                break;
            }
        }
        return res;
    }
};