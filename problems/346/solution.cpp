class MovingAverage {
private:
    int size;
    queue<int> q;
    double cur;
public:
    /** Initialize your data structure here. */
    MovingAverage(int _size): size{_size}, cur{0.0} {}
    
    double next(int val) {        
        if (q.size() == size) {
            cur -= q.front();
            q.pop();
        }
        
        cur += val;
        
        q.push(val);
        
        return cur / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */