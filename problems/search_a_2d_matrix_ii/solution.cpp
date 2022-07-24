class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        int start = matrix[0].back();
        while(i<m && j>=0){
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] < target)
                ++i;
            else --j;
        }
        return false;
    }
};