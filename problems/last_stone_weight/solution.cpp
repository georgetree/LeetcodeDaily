class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto i:stones)
            q.push(i);
        while(q.size()>1){
            int t1 = q.top();
            q.pop();
            int t2 = q.top();
            q.pop();
            if(t1==t2) continue;
            else if(t1!=t2){
                t1 = t1-t2;
                q.push(t1);
            }
        }
        return q.size()==1 ? q.top() : 0;
    }
};