class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1);

        return helper(arr, k, 0, dp);
    }
    
    int helper(vector<int>& arr, int k, int start, vector<int>& dp) {
        if (start >= arr.size()) {
            return 0;
        }
        
        if (dp[start]) {
            return dp[start];
        }
        
        int maxEl = 0, ans = 0;
        
        for (int i = start; i < min((int) arr.size(), start + k); i++) {
            maxEl = max(maxEl, arr[i]);
            ans = max(ans, maxEl * (i - start + 1) + helper(arr, k, i + 1, dp));
        }
        
        return dp[start] = ans;
    }
};