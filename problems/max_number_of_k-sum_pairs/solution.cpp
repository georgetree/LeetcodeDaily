class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int p1=0, p2=nums.size()-1;
        int res=0;
        sort(nums.begin(),nums.end());
        while(p1<p2){
            int t = nums[p1]+nums[p2];
            if(k==t){
                ++res;
                ++p1;
                --p2;
            }
            else{
                if(k > t)
                    ++p1;
                else 
                    --p2;
            }
        }
        return res;
    }
};