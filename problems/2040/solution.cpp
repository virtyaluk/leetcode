class Solution {
private:
    int helper(const vector<int>& nums2, const long long& x1, const long long& v) {
        int n = size(nums2),
            lo = 0,
            hi = n - 1,
            mid;
        
        while (lo <= hi) {
            mid = (lo + hi) / 2;

            if (x1 >= 0 and nums2[mid] * x1 <= v or x1 < 0 and nums2[mid] * x1 > v) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (x1 >= 0) {
            return lo;
        }
        
        return n - lo;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = size(nums1);
        long long lo = -1e10,
            hi = 1e10,
            mid,
            cnt;
        
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            cnt = 0;

            for (int i = 0; i < n; i++) {
                cnt += helper(nums2, nums1[i], mid);
            }

            if (cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return lo;
    }
};