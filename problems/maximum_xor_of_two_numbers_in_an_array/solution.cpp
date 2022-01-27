class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        for(int i=30; i>=0; i--){
            mask = mask | (1<<i);
            
            unordered_set<int> m;
            int targetMax = res | (1<<i);
            for(auto i : nums){
                if(m.find((i&mask)^targetMax)!=m.end()){
                    res = targetMax;
                    break;
                }
                else  m.insert(i&mask);
            }
        }
        return res;
    }
};