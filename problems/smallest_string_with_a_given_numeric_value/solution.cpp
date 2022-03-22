class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        k=k-n;
        for(int i=res.size()-1; i>=0; i--){
            int temp = min(25,k);
            res[i] = res[i] + temp;
            k = k - temp;
            
        }
        return res;
    }
};