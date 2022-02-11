class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26), v2(26);
        int l1 = s1.size();
        int l2 = s2.size();
        for(auto i:s1)
            v1[i-'a']++;
        for(int i=0; i< s2.size(); i++){
            if(i>=l1)
                v2[s2[i-l1] - 'a']--;
            v2[s2[i] - 'a']++;
            if(v1==v2) return true;
        }
        return false;
    }
};