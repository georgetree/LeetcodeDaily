class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsetlen = 1 << nums.size();
        vector<vector<int>> outPut;
        for(int i=0; i<subsetlen; ++i){
            vector<int> temp ;
            for(int j=0; j<nums.size(); ++j){
                if(((i>>j)&1) == 1)
                    temp.push_back(nums[j]);
            }
            outPut.push_back(temp);
        }
        return outPut;
    }
};