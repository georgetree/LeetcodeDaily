class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
     
        unordered_set<string> st{bank.begin(),bank.end()};
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        int res = 0;
        while(!q.empty()){
            int qs = q.size();
            for(int i=0; i<qs; i++){    
                string str = q.front();
                q.pop();
                if(str==end) return res;
                for(char k: "ACGT"){
                    for(int j=0; j<str.size(); j++){
                        string temp = str;
                        temp[j] = k;
                        if(st.count(temp) && !visited.count(temp)){
                            visited.emplace(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            ++res;
        }
        return -1;
    }
};