class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = size(arr), pre = 0, suf = n - 1, ans = 0;
        
        if (n <= 1) {
            return 0;
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] <= arr[i + 1]) {
                pre++;
            } else {
                break;
            }
        }
        
        if (pre == n - 1) {
            return 0;
        }
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) {
                suf--;
            } else {
                break;
            }
        }
        
        ans = min(suf, n - 1 - pre);
        
        for (int i = 0, j = suf; i <= pre and j <= n - 1;) {
            if (arr[i] <= arr[j]) {
                ans = min(ans, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return ans;
    }
};