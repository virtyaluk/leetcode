class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, n = size(arr);
        
        for (int i = 1, left = 0; i < n; i++) {
            int cmp = compare(arr[i - 1], arr[i]);
            
            if (cmp == 0) {
                left = i;
            } else if (i == n - 1 or cmp * compare(arr[i], arr[i + 1]) != -1) {
                ans = max(ans, i - left + 1);
                left = i;
            }
        }
        
        return ans;
    }
    
    int compare(int a, int b) {
        if (a == b) {
            return 0;
        }
        
        return a > b ? 1 : -1;
    }
};