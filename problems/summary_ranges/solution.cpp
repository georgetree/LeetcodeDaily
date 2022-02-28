class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int start=0;
        int i = 0;
        while(i++ < nums.size()){
            if(i== nums.size()||nums[i] != nums[i-1]+1){
                res.push_back(i-start==1 ? to_string(nums[start]) : to_string(nums[start]) + "->" + to_string(nums[i-1]));
                start = i;   
            }
          
        }
        return res;
    }
};