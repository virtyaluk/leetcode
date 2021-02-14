class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    int n;
    KthLargest(int k, vector<int>& nums) {
        n = k;
        
        for (int num: nums) {
            heap.push(num);
            
            if (heap.size() > n) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        
        if (heap.size() > n) {
            heap.pop();
        }
        
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */