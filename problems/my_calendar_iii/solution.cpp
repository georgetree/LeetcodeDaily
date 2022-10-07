class MyCalendarThree {
public:
    map<int,int> m;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++m[start];
        --m[end];
        int res = 0, count = 0;
        for(auto it=m.begin(); it!=m.end(); it++){
            count += it->second;
            res = max(res,count);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */