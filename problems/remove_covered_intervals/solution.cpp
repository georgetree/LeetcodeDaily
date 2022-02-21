class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int res = 0;
        int left = -1;
        int right = -1;
        for(auto cur : intervals){
            if(cur[0] > left && cur[1] > right){
                res++;
                left = cur[0];
            }
            right = max(right, cur[1]);
        }
        return res;
    }
};