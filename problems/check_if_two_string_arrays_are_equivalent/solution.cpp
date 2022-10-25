class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b;
        for(auto &w:word1){
            for(auto c:w){
                a += c;
            }
        }
        for(auto &w:word2){
            for(auto c:w){
                b += c;
            }
        }
        return a==b;
    }
};