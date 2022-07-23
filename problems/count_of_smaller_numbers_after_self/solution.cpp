class Solution {
public:
    
    int lowerBit(int x){
         return x & (-x);
    }
    void update(int i, vector<int> &t){
        while(i < t.size()){
            t[i] +=1;
            i += lowerBit(i);
        }    
    }
    int query(int i,vector<int> &t){
        int sum = 0;
        while(i > 0){
            sum+= t[i];
            i -= lowerBit(i);
        }
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        set<int> s(nums.begin(),nums.end());
        unordered_map<int,int> m;
        int r = 1;
        for(auto i: s){
            m[i] = r++;
        }
        vector<int> tree(nums.size()+1,0);
        for(int i=nums.size()-1; i>=0; i--){
            res.push_back(query(m[nums[i]]-1,tree));
            update(m[nums[i]],tree);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};