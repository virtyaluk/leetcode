class Solution {
private:
    int toRemove[100001];
    
public:
    int maximumRemovals(string s, string p, vector<int>& rem) {
        int lo = 0, hi = size(rem);
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (check(s, p, rem, mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return hi;
    }
    
    bool check(string& s, string& p, vector<int>& rem, int k) {
        int i = 0, j = 0, m = size(s), n = size(p);
        
        memset(toRemove, 0, sizeof(toRemove));
        
        for (int i = 0; i < k; i++) {
            toRemove[rem[i]] = 1;
        }
        
        for (; i < m and j < n; i++) {
            if (toRemove[i] == 1) {
                continue;
            }
            
            if (s[i] == p[j]) {
                j++;
            }
        }
        
        return j == n;
    }
};