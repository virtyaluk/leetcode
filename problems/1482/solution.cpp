class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (m * k > size(bloomDay)) {
            return -1;
        }
        
        int lo = 1, hi = *max_element(begin(bloomDay), end(bloomDay));
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(bloomDay, m, k, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        // cout << "lo: " << lo << ", hi: " << hi << endl;
        
        return lo;
    }
    
    bool check(const vector<int>& bloomDay, int m, int k, int d) {
        int ans = 0, adjCount = 0;
        
        for (int i = 0; i < size(bloomDay); i++) {
            if (bloomDay[i] > d) {
                adjCount = 0;
                continue;
            }
            
            adjCount++;
            
            if (adjCount == k) {
                ans++;
                adjCount = 0;
            }
        }
        
        return ans >= m;
    }
};