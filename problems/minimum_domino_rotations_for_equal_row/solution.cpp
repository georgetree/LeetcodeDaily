class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> a(7),b(7),s(7);
        
        for(int i=0; i<tops.size();i++){
            ++a[tops[i]];
            ++b[bottoms[i]];
            if(tops[i]==bottoms[i]) ++s[tops[i]];
        }
        for(int j=1; j<7; j++){
            if(a[j]+b[j]-s[j]==tops.size())
                return tops.size() - max(a[j],b[j]);
        }
        return -1;
    }
};