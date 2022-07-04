class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res (ratings.size(),1);
        for(int i=1; i< ratings.size(); i++){
            if(ratings[i] > ratings[i-1]) res[i] = res[i-1]+1;
        }
        for(int k=ratings.size()-1; k>0; k--){
            if(ratings[k] < ratings[k-1]) res[k-1] = max(res[k]+1, res[k-1]);
        }
        return accumulate(res.begin(),res.end(),0);
    }
};