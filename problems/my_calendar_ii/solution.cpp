class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int count = 0;
        for(auto it=m.begin(); it!=m.end(); it++){    
            count+= it->second;
            if(count==3){
                m[start]--;
                m[end]++;
                return false;  
            } 
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */