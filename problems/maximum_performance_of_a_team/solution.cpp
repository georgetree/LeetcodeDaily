class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int,int>> es(n);
        for(int i=0; i<n; i++)
            es[i] = {e[i],s[i]};
        sort(rbegin(es),rend(es));
        priority_queue<int,vector<int>, greater<int>>q;
        long long res = 0,sum = 0;
        long long M = 1e9+7;
        for(int i=0; i<n; i++){
            sum += es[i].second;
            q.push(es[i].second);
            if(q.size()>k){
                sum -=  q.top();
                q.pop();
            }
            res = max(res,sum*es[i].first);
        }
        return res%M;
    }
};