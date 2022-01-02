class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> hash;
	    int res = 0;
        
        for(auto &a: time){
            int remainder = a % 60;
            if(hash.find(remainder) != hash.end()){
                res += hash[remainder];
            }
            int t = remainder == 0 ? 0 : 60-remainder;
            hash[t]+=1;
        }
        return res;
    }
};