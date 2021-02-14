class MyCalendar {
private:
    map<int, int> m; // m[end] = start;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto next = m.upper_bound(start);
        
        if (next != m.end() and next->second < end) {
            return false;
        }
        
        m[end] = start;
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */