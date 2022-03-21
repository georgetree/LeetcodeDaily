class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        vector<int> res;
        
        for(int i=0; i<s.size();i++)
            m[s[i]]= i;
        int current = m[s[0]];
        int count = 1;
        for(int j=0; j<s.size();j++){
            current = max(current, m[s[j]]);
            if(current == j){
                res.push_back(count);
                count = 1;
            }
            else{
                count++;
            }
        }
        return res;
    }
};