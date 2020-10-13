class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //vector<int> result;
        unordered_map<int, int> imap;

 
        for (int i = 0;nums.size(); ++i) {
            if(imap.find(target-nums[i])!=imap.end()){
                return { i,imap[target - nums[i]]};
            }
            imap[nums[i]] = i;

        }

        return {};

    }
};