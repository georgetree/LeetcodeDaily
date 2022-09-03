/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int l = 0;
        int r = len-1;
        int peek = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                l = peek = mid+1;
            else r = mid-1;
        }
        l = 0;
        r = peek;
        while(l<=r){
            int mid = (l+r)/2;
            int t = mountainArr.get(mid);
            if(t < target) l = mid+1;
            else if(t > target) r = mid-1;
            else return mid;
        }
        l = peek;
        r = len-1;
        while(r>=l){
            int mid = (l+r)/2;
            int t = mountainArr.get(mid);
            if(t > target) l = mid+1;
            else if(t < target) r = mid-1;
            else return mid;
        }
        return -1;
    }
};