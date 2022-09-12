class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (arr[mid] - mid - 1 < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo + k;
    }
    int findKthPositive1(vector<int>& arr, int k) {
        int ans = 1, n = arr.size(), i = 0;
        
        while (k > 0) {
            if (i < n && arr[i] == ans) {
                i++;
            } else {
                k--;
            }
            
            ans++;
        }
        
        return ans - 1;
    }
};