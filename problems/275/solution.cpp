class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = size(citations), lo = 0, hi = n - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (citations[mid] < n - mid) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return n - lo;
    }
};