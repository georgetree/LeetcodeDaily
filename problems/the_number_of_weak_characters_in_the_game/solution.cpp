class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](vector<int> &a,vector<int> &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        int res = 0, s = 0;    
        for(auto & i:p){
            if(i[1] < s) res++;
            else s = i[1];
        }
        return res;
    }
};