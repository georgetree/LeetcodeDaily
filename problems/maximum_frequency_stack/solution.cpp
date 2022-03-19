class FreqStack {
public:
    unordered_map<int,int>m;
    unordered_map<int,stack<int>> st;
    int Freq;
    FreqStack() {
        
    }
    
    void push(int val) {
        Freq = max(Freq, ++m[val]);
        st[m[val]].push(val);
    }
    
    int pop() {
        int res = st[Freq].top();
        st[Freq].pop();
        if(!st[m[res]].size()) Freq--;
        m[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */