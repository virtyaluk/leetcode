class Solution {
private:
    bool canDistribute(vector<int>& quantities, const int n, const int k) {
        for (int i = 0, j = 0, rem = quantities[j]; i < n; i++) {
            if (rem <= k) {
                j++;
                
                if (j == size(quantities)) {
                    return true;
                } else {
                    rem = quantities[j];
                }
            } else {
                rem -= k;
            }
        }
        
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 0,
            hi = *max_element(begin(quantities), end(quantities));
        
        if (size(quantities) >= n) {
            return hi;
        }
        
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            if (canDistribute(quantities, n, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};