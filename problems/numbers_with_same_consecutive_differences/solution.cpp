class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        for(int i=1; i<n; i++){
            vector<int> c;
            for(int num:nums){
                int d = num%10;
                if(d+k <= 9) c.push_back(num*10+d+k);
                if(k>0 && d-k >=0) c.push_back(num*10+d-k);
            }
            nums = c;
        }
        return nums;
    }
};