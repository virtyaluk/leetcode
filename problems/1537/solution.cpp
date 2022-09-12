class Solution {
public:
    int maxSum(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0, m = a.size(), n = b.size();
        long long int sa = 0, sb = 0, mod = 1e9 + 7;
        
        while (i < m or j < n) {
            if (i < m and (j == n or a[i] < b[j])) {
                sa += a[i++];
            } else if (j < n and (i == m or a[i] > b[j])) {
                sb += b[j++];
            } else {
                sa = sb = max(sa, sb) + a[i];
                i++;
                j++;
            }
        }
        
        return max(sa, sb) % mod;
    }
};