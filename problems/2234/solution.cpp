class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int fullCnt = 0;
        
        sort(begin(flowers), end(flowers));
        
        for (int i = size(flowers) - 1; i >= 0; i--) {
            if (flowers[i] < target) {
                break;
            }
            
            fullCnt++;
        }
        
        int n = size(flowers) - fullCnt;
        
        if (not n) {
            return (long long) fullCnt * (long long) full;
        }
        
        vector<long long> fillUp(n, 0),
            fillTarget(n, 0);
        
        fillUp[0] = 0;
        
        for (int i = 1; i < n; i++) {
            fillUp[i] = (flowers[i] - flowers[i - 1]) * (long long) i + fillUp[i - 1];
        }
        
        fillTarget[n - 1] = (long long) target - flowers[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            fillTarget[i] = fillTarget[i + 1] + (long long)(target - flowers[i]);
        }
        
        long long ans = 0;
        
        for (int numFill = 0; numFill <= n; numFill++) {
            long long m = 0,
                rm = newFlowers;
            
            if (numFill != 0) {
                rm -= fillTarget[n - numFill];
            }
            
            if (rm < 0) {
                break;
            }
            
            if (numFill != n) {
                auto it = upper_bound(begin(fillUp), end(fillUp), rm);
                int idx = it - begin(fillUp);
                
                if (idx >= n - numFill) {
                    idx = n - numFill;
                }
                
                m = flowers[idx - 1];
                m += (rm - fillUp[idx - 1]) / idx;
                m = min(m, (long long) target - 1);
            }
            
            long long tmp = m * (long long) partial + (fullCnt + numFill) * (long long) full;
            ans = max(ans, tmp);
        }
        
        return ans;
    }
};