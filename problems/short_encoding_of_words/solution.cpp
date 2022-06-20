class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int res = 0;
        for(int i=0; i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
        }
        sort(words.begin(),words.end());
        for(auto it = words.begin(); next(it)!=words.end(); it++){
            if(*it != next(it)->substr(0,it->size())) res += it->size()+1; 
        }
                
        return res + words.rbegin()->size()+1;
    }
};