class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int a = 0, b = arr.size()-1;
        
        while(arr.size()>k){
            if(abs(x - arr.front()) > abs(arr.back()-x)) arr.erase(arr.begin());
            else arr.pop_back();
        }
        return arr; 
    }
};