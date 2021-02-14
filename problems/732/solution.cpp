class MyCalendarThree {
private:
    map<int, int> m;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        
        int ans = 0, cur = 0;
        
        for (auto [ignore, diff]: m) {
            cur += diff;
            ans = max(ans, cur);
        }
        
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */