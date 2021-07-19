class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
        int c = 0, ar = intervals[0][1];
        for(int i=1; i < intervals.size(); i++){
            if(intervals[i][0] < ar)
                c++;
            else
                ar = intervals[i][1];
        }
        return c;
    }
};