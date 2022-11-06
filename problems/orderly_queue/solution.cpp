class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
        }
        else{
            string temp = s;
            for(int i=1; i<s.size(); i++){
                temp += temp[0];
                temp.erase(0,1);
                s = min(s,temp);
            }
        }
        return s;
    }
};