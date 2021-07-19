class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> umap;
        for(int i=0; i < s.size(); i++) 
            umap[s[i]] = i;
        int count = 1;
        int curr = umap[s[0]];
        vector<int> result;
        for(int j=0; j < s.size(); j++){
            curr = max(umap[s[j]],curr);
            if(curr == j){
                result.push_back(count);
                count = 1;
            }           
            else
                count ++;
        }
        return result;
    }
};