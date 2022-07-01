class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();

        for(int i=0; i<=m-n; i++){
            int count = 0;
            for(int j=0; j<needle.size(); j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                count++; 
            }
            if(count == needle.size())
                return i; 
 
        }
        return -1;
    }
};