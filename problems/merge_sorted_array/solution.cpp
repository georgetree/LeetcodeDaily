class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t = nums1.size()-1;
        n--;
        m--;
        while(n>=0){
            if(m>=0 && nums1[m] >= nums2[n]){
                nums1[t] = nums1[m];
                m--;
                t--;
            }
            else{
                nums1[t] = nums2[n];
                n--;
                t--;
            }

        }
        
    }
};