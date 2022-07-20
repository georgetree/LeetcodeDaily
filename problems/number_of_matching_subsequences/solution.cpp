class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        int n = s.size();
        unordered_set<string> m1, m2;
        for(auto word:words){
            if(m1.count(word) || m2.count(word)){
                if(m1.count(word)) res++;
                continue;
            }
            int pos = 0;
            int count = 0;
            int i = 0, j=0, m = word.size();
            while(i<n && j<m){
                if(s[i] == word[j]) ++j;
                i++;
            }
             
            if(j == word.size()){
                m1.insert(word); 
                res++;
            }
            else m2.insert(word);
        }
        return res;
    }
};