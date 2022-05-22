class Solution {
public:
    int countSubstrings(string s)
    {
        int ans =0;
        for(int i =0;i < 2 * s.size();i++)
        {
            int left = i/2, right = left + i % 2 ;
            while(left >= 0 && right < s.size() && s[left]  == s[right])
            {
                --left;
                ++right;
                ++ans;
            }
        }
        return ans;
    }
};
