class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> q(target.begin(),target.end());
        long sum = 0;
        sum = accumulate(target.begin(),target.end(),0LL);
    
        while(1){
            int t = q.top();
            q.pop();
            sum -=t;
            if(sum == 1 || t==1) return true;
            if(t < sum || sum==0 || t % sum==0) return false;
            t = t % sum;
            sum+=t;
            q.push(t);
        }
    }
};