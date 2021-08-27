class FreqStack {
private:
    priority_queue<tuple<int, int, int>> pq;
    unordered_map<int, int> freq;
    int pos = 0;
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        freq[x]++;
        pq.push({freq[x], pos++, x});
    }
    
    int pop() {
        const auto [a, b, num] = pq.top();
        
        pq.pop();
        freq[num]--;
        
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */