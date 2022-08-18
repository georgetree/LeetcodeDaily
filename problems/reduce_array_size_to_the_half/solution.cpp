class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto const &a: arr)
            m[a]++;
        int res = 0, t = 0;
        priority_queue<int> q;
        for(auto it:m){
            if(it.second >= arr.size()/2)
                return ++res;
            q.push(it.second);
        }
        while(!q.empty()){
            t+=q.top();
            q.pop();
            res++;
            if(t>=arr.size()/2) break;
        }
        return res;
    }
};