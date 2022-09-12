class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = size(arr);
        set<int> s = {0, n + 1};
        
        if (n == m) {
            return n;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            auto lo = *--s.lower_bound(arr[i]);
            auto hi = *s.upper_bound(arr[i]);
            
            if (arr[i] - lo - 1 == m or hi - 1 - arr[i] == m) {
                return i;
            }
            
            s.insert(arr[i]);
        }
        
        return -1;
    }
};