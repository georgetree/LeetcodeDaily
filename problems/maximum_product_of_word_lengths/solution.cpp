class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> m(words.size(),0);
        for(int i=0; i<words.size(); i++){
            for(char word: words[i]){
                m[i] |= 1 << (word - 'a');
            }
            for(int j=0; j<i; j++){
                if(!(m[j] & m[i]))
                    res = max(res, int(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};