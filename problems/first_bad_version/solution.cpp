// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(l<=r){
            int mid = (r-l)/2+l;
            if(isBadVersion(mid)==false) l = mid+1;
            else if(isBadVersion(mid)) r = mid-1;
        }
        return l;
    }
};