class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(s.find(endWord) == s.end()) return 0;
        
        queue<string> q{{beginWord}};
        
        int l = beginWord.length();
        int step = 0;
        
        while(!q.empty()){
            ++step;
            for (int size = q.size(); size > 0; size--) {                
                string w = q.front();                
                q.pop();
                for(int i=0; i<l; i++){
                    char t = w[i];
                    for(int j = 0; j < 26; ++j ){
                        w[i] = 'a' + j;
                        if(w == endWord) return step+1;
                        if (!s.count(w)) continue;
                        s.erase(w);
                        q.push(w);

                    }
                    w[i] = t;
                }
            }
        }
        return 0;

    }
};