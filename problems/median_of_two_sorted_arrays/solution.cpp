class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> nums3;
      nums3.insert(nums3.end(),nums1.begin(),nums1.end());
      nums3.insert(nums3.end(),nums2.begin(),nums2.end());
      sort(nums3.begin(),nums3.end());
      if((int)nums3.size()%2==0){
       return (nums3[((double)nums3.size()/2.0)-1]+nums3[(double)nums3.size()/2.0])/2.0;
      }else{
       return nums3[((double)nums3.size()/2.0) ];
      }
    }
};