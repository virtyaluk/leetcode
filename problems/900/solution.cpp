class RLEIterator {
private:
    vector<int>& enc;
    int i = 0;

public:
    RLEIterator(vector<int>& encoding): enc{encoding} {}
    
    int next(int n) {
        while (i < size(enc) and n > enc[i]) {
            n -= enc[i];
            i += 2;
        }
        
        if (i >= size(enc)) {
            return -1;
        }
        
        enc[i] -= n;
        
        return enc[i + 1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */