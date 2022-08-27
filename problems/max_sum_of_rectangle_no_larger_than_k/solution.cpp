class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int res = INT_MIN;
        for(int i=0; i<col; i++){
            vector<int> v(row,0);
            for(int j=i; j<col; j++){
                int ka = 0, kt = INT_MIN;
                for(int r=0; r<row; r++){
                    v[r] += matrix[r][j];
                    ka = max(ka+v[r],v[r]);
                    kt = max(kt,ka);
                }
                if(kt <= k){
                    if(kt==k) return k;
                    res = max(res,kt);
                }
                else{
                    for(int bt = 0; bt<row; bt++){
                        int temp = 0;
                        for(int b = bt; b<row; b++){
                            temp += v[b];
                            if(temp <= k){
                                if(temp ==k) return k;
                                res = max(res,temp);
                            }
                        }
                    }
                }
            }
        }        
        return res;
    }
};