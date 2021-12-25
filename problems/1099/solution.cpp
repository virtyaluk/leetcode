class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        
        int ans = -1, lo = 0, hi = A.size() - 1;
        
        while (lo < hi) {
            if (A[lo] + A[hi] < K) {
                ans = max(ans, A[lo] + A[hi]);
                lo++;
            } else {
                hi--;
            }
        }
        
        return ans;
    }
};