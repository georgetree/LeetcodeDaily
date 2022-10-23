class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(nums.size()+1,0);
        vector<int> res;
        for(int n:nums) {
            v[n]++;
            if(v[n]>1) res.push_back(n);
        }
        for(int i=1; i<=nums.size(); i++){
            if(v[i]==0) res.push_back(i);
        }
        return res;
    }
};