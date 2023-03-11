class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = 1,
            hi = 1e14;
        
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2,
                total = 0;
            
            for (const int& t: time) {
                total += mid / t;
            }
            
            if (total < totalTrips) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
};