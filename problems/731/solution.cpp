class MyCalendarTwo {
private:
    map<int, int> m;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int overlap = 0;
        
        for (auto [_, t]: m) {
            overlap += t;
            
            if (overlap > 2) {
                m[start]--;
                m[end]++;
                
                if (m[start] == 0) {
                    m.erase(start);
                }
                
                if (m[end] == 0) {
                    m.erase(end);
                }
                
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