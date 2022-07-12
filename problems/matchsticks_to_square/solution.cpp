class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.empty() || matchsticks.size() < 4) return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(),matchsticks.rend());
        return helper(matchsticks, 0, sum/4, sides);
    }
    bool helper(vector<int> &matchsticks, int len, int target, vector<int> &sides){
        if(len>=matchsticks.size())
            return true;
        for(int i=0; i<4; i++){
            if(sides[i]+matchsticks[len] > target || (i>0 && sides[i]==sides[i-1])) continue;
            sides[i] += matchsticks[len];
            if(helper(matchsticks,len+1,target,sides))
                return true;
            sides[i] -= matchsticks[len];
        }
        return false;
    }
};