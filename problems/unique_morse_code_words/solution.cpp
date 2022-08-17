class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> m;
        for(auto const &word:words){
            string t = "";
            for(auto const &w:word){
                t+=v[w-'a'];
            }
            m.emplace(t);
        }
        return m.size();
    }
};