class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo = 1, hi = 1e8;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(dist, mid) <= hour) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        // cout << "lo: " << lo << ", hi: " << hi << endl;
        return lo >= 1e8 ? -1 : lo;
    }
    
    double check(const vector<int>& dist, double mid) {
        double ans = 0.0;
        
        for (int i = 0; i < size(dist); i++) {
            double d = dist[i];
            
            if (i == size(dist) - 1) {
                ans += d / mid;
            } else {
                ans += ceil(d / mid);
            }
        }
        
        return ans;
    }
};