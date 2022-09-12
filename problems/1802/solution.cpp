class Solution {
private:
    bool check(int n, int index, int maxSum, int k) {
        index++;
        long long int sum = n;
        k--;
        int l = min(index, k), r = min(k, n - index + 1);
        
        sum -= k;
        sum += (long long int)(k - l + 1 + k) * l / 2;
        sum += (long long int)(k - r + 1 + k) * r / 2;
        
        return sum <= maxSum;
    }

public:
    int maxValue(int n, int index, int maxSum) {
        int lo = 1, hi = maxSum;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(n, index, maxSum, mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return hi;
    }
};