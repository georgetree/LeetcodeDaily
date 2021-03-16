class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        int curL = 0, curR = 0;
        int cur = 0, n = s.size();
        while (cur < n)
        {
            left = cur;
            right = cur;
            for(; right<n-1 && s[right] == s[right+1]; right++);
            cur = right+1;
            for(; left>0 && right<n-1 && s[left-1] == s[right+1]; left--, right++);
            
            if(right-left > curR-curL)
            {
                curL = left;
                curR = right;
            }
        }
        return s.substr(curL, curR-curL+1);
    }
};
