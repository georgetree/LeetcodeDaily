class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int l = 0, r = tokens.size()-1, count = 0;
        int res = 0;
        while(l<=r){
            if(power >= tokens[l]){
                power -= tokens[l];
                l++;
                count++;
                res = max(res,count);
            }
            else if(count > 0){
                count--;
                power += tokens[r];
                r--;
            }
            else{
                break;
            }
        }
        return res;
    }
};