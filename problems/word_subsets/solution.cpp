class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
   
        vector<int> m(26,0);
        for(auto const &w: words2){
            vector<int> n(26,0);
            for(auto const &j: w){
                n[j-'a']++;
            }
            for(int i=0; i<26; i++)
                m[i] = max(m[i],n[i]);
        }
        for(auto const &i:words1){
            vector<int> n(26,0);
            for(auto const &t: i){
                n[t-'a']++;
            }
            bool flag = true;
            for(int j=0; j<26; j++){
                if(n[j] < m[j]){
                    flag = false;
                    break;
                } 
            }
            if(flag) res.push_back(i);
        }
        return res;
    }
};