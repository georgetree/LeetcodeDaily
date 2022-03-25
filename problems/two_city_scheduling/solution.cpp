class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        vector<int> temp;
        for(auto i:costs){
            res+=i[0];
            temp.push_back(i[1]-i[0]);
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i=0; i<costs.size()/2; i++){
            res+=temp[i];
        }
        return res;
    }
};