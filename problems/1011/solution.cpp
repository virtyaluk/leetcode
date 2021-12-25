class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int lo = INT_MIN, hi = 0;
        
        for (const int& weight: weights) {
            hi += weight;
            lo = max(lo, weight);
        }
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(weights, D, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
    
    bool check(vector<int>& weights, int d, int cap) {
        int curCap = 0;
        d--;
        
        for (const int& weight: weights) {
            if (curCap + weight <= cap) {
                curCap += weight;
            } else {
                curCap = weight;
                d--;
            }
        }
        
        return d >= 0;
    }
};