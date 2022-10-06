class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(auto &t: tasks) {
            v[t-'A']++;
        }
        sort(v.begin(),v.end(),greater<int>());

        int i = 0, mx = v[0], len = tasks.size();
        while(i<v.size() && v[i]==mx) i++;
        return (max(len,(mx-1)*(n+1)+i));
    }
};