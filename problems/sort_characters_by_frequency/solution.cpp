class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map <char,int> m;
        priority_queue <pair<int,char>> q;
        for(char a : s) 
            m[a]+=1;
        for(auto i: m)  
            q.push({i.second,i.first});
        while(!q.empty()){
            auto a = q.top(); 
            q.pop();
            cout << a.first << a.second << endl;
            res.append(a.first,a.second);
        }  
        return res;
    }
};