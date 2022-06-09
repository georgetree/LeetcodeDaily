class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
 
        int l = 0, r = numbers.size()-1;;
        vector<int> res;
        while(l<r){
            int t = numbers[l]+numbers[r];
            if(t>target)
                r--;
            else if(t<target)
                l++;
            else return {l+1,r+1};
                
        }
        return {};
    }
};