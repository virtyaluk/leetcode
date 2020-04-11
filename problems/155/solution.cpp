class MinStack {
public:
    deque<pair<int, int>> q;
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        q.push_back({val, min(getMin(), val)});
    }
    
    void pop() {
        q.pop_back();
    }
    
    int top() {
        return q.back().first;
    }
    
    int getMin() {
        if (q.empty()) {
            return INT_MAX;
        }
        
        return q.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */