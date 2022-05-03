class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int l = -1, r=-2; //-2原因是如果結果為0則不必在額外判斷
        int n = nums.size();
        int p1 = nums[0], p2 = nums[n-1];
        for(int i=1; i<n; i++){
            p1 = max(nums[i],p1);
            p2 = min(nums[n-i-1],p2);
            
            if(p1 > nums[i]) r = i;
            if(p2 < nums[n-i-1]) l = n-i-1;
        }
        
        return r-l+1;
    }
};

