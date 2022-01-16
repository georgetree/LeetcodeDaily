class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int t = -1;
        int n = seats.size();
        for(int i=0; i<n; i++){
            if(seats[i] == 1){
                res = t < 0 ? i : max(res,(i-t)/2); 
                t = i;
            }
        }
        res = max(res, n-t-1);
        return res;
    }
};