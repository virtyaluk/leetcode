class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = size(nums1), n = size(nums2), k = (m + n + 1) / 2;
        double ans = findKthSmallest(nums1, 0, m - 1, nums2, 0, n - 1, k);
        
        if ((m + n) % 2 == 0) {
            ans += findKthSmallest(nums1, 0, m - 1, nums2, 0, n - 1, k + 1);
            ans *= 0.5;
        }
        
        return ans;
    }
    
    double findKthSmallest(vector<int>& a, int alo, int ahi, vector<int>& b, int blo, int bhi, int k) {
        cout << k << endl;
        if (alo > ahi) {
            return b[blo + k - 1];
        }
        
        if (blo > bhi) {
            return a[alo + k - 1];
        }
        
        int amid = alo + (ahi - alo) / 2,
            bmid = blo + (bhi - blo) / 2;
        
        if (a[amid] <= b[bmid]) {
            if (k <= (amid - alo) + (bmid - blo) + 1) {
                return findKthSmallest(a, alo, ahi, b, blo, bmid - 1, k);
            } else {
                return findKthSmallest(a, amid + 1, ahi, b, blo, bhi, k - (amid - alo) - 1);
            }
        } else {
            if (k <= (amid - alo) + (bmid - blo) + 1) {
                return findKthSmallest(a, alo, amid - 1, b, blo, bhi, k);
            } else {
                return findKthSmallest(a, alo, ahi, b, bmid + 1, bhi, k - (bmid - blo) - 1);
            }
        }
        
        return 0.0;
    }
};

/*

[3, 4, 6, 10, 13, 15, 19]
[10, 11, 14, 16, 18, 20]

3, 4, 6, 10, 10, 11, 13, 14, 15, 16, 18, 19, 20

*/