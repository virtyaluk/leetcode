class Solution {
private:
    vector<int> pre;
public:
    Solution(vector<int>& w) {
        for (const int& num: w) {
            pre.push_back(num + (empty(pre) ? 0 : pre.back()));
        }
    }
    
    int pickIndex() {
        int randVal = rand() % pre.back() + 1;
        
        
        return bs(randVal);
    }
    
    int bs(int x) {
        int lo = 0, hi = size(pre) - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (pre[mid] >= x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */