class MRUQueue {
private:
    deque<int> dq;

public:
    MRUQueue(int n) {
        for (int i = 1; i <= n; i++) {
            dq.push_back(i);
        }
    }
    
    int fetch(int k) {
        int ans = dq[--k];
        
        dq.erase(begin(dq) + k);
        dq.push_back(ans);
        
        return ans;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */