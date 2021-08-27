class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        
        int ans = A.back() - A[0];
        
        for (int i = 0; i < A.size() - 1; i++) {
            int a = A[i], b = A[i + 1];
            int hi = max(A.back() - K, a + K), lo = min(A[0] + K, b - K);
            ans = min(ans, hi - lo);
        }
        
        return ans;
    }
};