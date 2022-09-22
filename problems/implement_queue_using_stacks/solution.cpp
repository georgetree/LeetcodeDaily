class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;
    stack<int> st2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        st2.push(x);
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = st.top();
        st.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        return st.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */