class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1)
            return s; 
        vector<string> arr(min(numRows, (int)s.size()));
        int cur = 0;
        bool dir = false;
        string restr;
        for(int i=0 ; i<s.size(); i++){
            arr[cur] += s[i];
            if(cur==0 || cur == numRows-1)
                dir = !dir ;
            cur += dir ? 1 : -1 ;
        }
        for(auto sc : arr)
            restr+=sc;
       return restr;
    }
};