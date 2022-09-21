class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int sumEven = accumulate(nums.begin(),nums.end(),0,[](int res,int x){
            if((x%2)==0)
                return res+x;
            else return res;
        });
        
        for(auto &q: queries){
            if((nums[q[1]] % 2) == 0){
                sumEven = sumEven-nums[q[1]];
            }
            nums[q[1]] += q[0];
            if((nums[q[1]]%2) == 0) sumEven += nums[q[1]];
            res.push_back(sumEven);
        }
        return res;
    }
};