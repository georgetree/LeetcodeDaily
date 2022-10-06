class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int z = 0, o = 0;
        for(auto &c: s){
            if(c == '0') z = min(z+1,o);
            else o++;
        }
        return z;
    }
};