class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';
        string res = "";
        for(int i=1, j=0; i<d.size(); i++){
            if(d[i]=='.') continue;
            if(j!=0) res += d[j];
            int mid = i - j - 1;
            if(d[i]==d[j]) res += string(mid,d[j]);
            else if(d[j]=='L' || d[i] == 'R') res += string(mid,'.');
            else if(d[j]=='R' && d[i]== 'L'){
                res += string(mid/2,'R') + string(mid%2,'.') + string(mid/2,'L');
            }
            j = i;
        }
        return res;
    }
};