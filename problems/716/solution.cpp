class MaxStack {
private:
    list<int> st;
    map<int, list<list<int>::iterator>> m;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
        m[x].push_back(--end(st));
    }
    
    int pop() {
        int x = st.back();
        
        st.pop_back();
        m[x].pop_back();
        
        if (empty(m[x])) {
            m.erase(x);
        }
        
        return x;
    }
    
    int top() {
        return st.back();
    }
    
    int peekMax() {
        return rbegin(m)->first;
    }
    
    int popMax() {
        int x = rbegin(m)->first;
        st.erase(m[x].back());
        m[x].pop_back();
        
        if (empty(m[x])) {
            m.erase(x);
        }
        
        return x;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */