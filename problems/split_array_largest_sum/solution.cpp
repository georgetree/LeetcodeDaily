class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long r = 9; //sum of nums
        int l = nums[0]; // nums max element
        for(auto i:nums){
            r += i;
            l = i < l ? l : i;
        }
        
        while(l < r){
            int temp = 0;
            int mid = (l+r)/2;
            int cnt = 1;    
            for(auto i:nums){
                temp +=i;
                if(temp > mid){
                    cnt++;
                    temp = i;
                }
            }
            if(cnt > m)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};