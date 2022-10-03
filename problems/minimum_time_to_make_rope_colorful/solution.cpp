class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        char t =colors[0];
        for(int i=1; i<colors.size(); i++){
            if(colors[i] == t){
                res += min(neededTime[i-1], neededTime[i]);
                if(neededTime[i-1]>neededTime[i])
                    swap(neededTime[i-1], neededTime[i]);
                
            }
            else t = colors[i];
        }
        return res;
    }
};