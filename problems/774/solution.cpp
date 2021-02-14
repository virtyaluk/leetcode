class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double lo = 0, hi = 1e8;
        
        while (hi - lo > 1e-6) {
            double mid = lo + (hi - lo) / 2.0;
            
            if (check(stations, k, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        
        return lo;
    }
    
    bool check(vector<int>& stations, int k, double d) {
        int used = 0;
        
        for (int i = 0; i < size(stations) - 1; i++) {
            used += ((double) (stations[i + 1] - stations[i])) / d;
        }
        
        return used <= k;
    }
};