class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> num(ratings.size(),1);
        for(int i=1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1])
                num[i] = num[i-1] + 1;
        }
        for(int k=ratings.size()-1; k>0; k--){
            if(ratings[k-1] > ratings[k] )
                num[k-1] = max(num[k-1]  , num[k]+1);
        }
        return accumulate(num.begin(),num.end(),0);
    }
};