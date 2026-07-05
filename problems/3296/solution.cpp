class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long lo = 0,
            hi = 1e18,
            ans = hi;
        
        sort(begin(workerTimes), end(workerTimes));

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2,
                cnt = 0;
            
            for (const int& t: workerTimes) {
                long long k = (long long) ((sqrt(1 + 8.0 * mid / t) - 1) / 2);
                cnt += k;

                if (cnt >= mountainHeight) {
                    break;
                }
            }

            if (cnt >= mountainHeight) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};