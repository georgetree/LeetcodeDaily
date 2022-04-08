class KthLargest {
public:
    int K;
    priority_queue <int, vector<int>, greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        for(auto i:nums){
            q.push(i);
            if(q.size()>k)
                q.pop();
        }
        K = k;
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>K)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */