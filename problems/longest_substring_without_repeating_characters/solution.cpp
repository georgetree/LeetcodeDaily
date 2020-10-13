class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int maxsize = 0;
    vector<char> temp;
    vector<char>::const_iterator it;

    for(int i=0;i<s.length();i++){
        if( find(temp.begin(), temp.end(), s[i]) != temp.end()){
          temp.erase(temp.begin(),next(find(temp.begin(), temp.end(), s[i]))); 
        }
        temp.push_back(s[i]) ;
        maxsize = max(maxsize,(int)temp.size());
    }
        return maxsize;
    }
};