class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3 || arr[0] > arr[1]) return false;
        int flag = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > arr[i-1] && flag == 0) return false;
            if(arr[i] < arr[i-1]) {
                flag = 0;
            }
            if(arr[i] == arr[i-1]) return false;
        }
        return flag==1 ? false : true;
    }
};