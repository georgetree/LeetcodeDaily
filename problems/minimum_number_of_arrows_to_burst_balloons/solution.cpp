class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        int c = 1, p = points[0][1];
        for(int i=1; i < points.size(); i++){
            if( p >= points[i][0] )
                p = min(p,points[i][1]);
            else{
                c++;
                p = points[i][1];
            }
                
        }
        return c;

    }
};