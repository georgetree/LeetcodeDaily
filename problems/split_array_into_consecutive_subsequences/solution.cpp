class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>m,n;
        for(int const &n:nums)
            m[n]++;
        for(int i:nums){
            if(m[i]==0) continue;
            m[i]--;
            if(n[i-1]>0){
                n[i-1]--;
                n[i]++;
            }
            else if(m[i+1]>0 && m[i+2]>0){
                m[i+1]--;
                m[i+2]--;
                n[i+2]++;
            }
            else return false;
        }
        return true;
    }
};