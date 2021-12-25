class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        int ans = 1;
        unordered_map<int, int> dp{
            {arr.front(), 1}
        };
        
        for (int i = 1; i < size(arr); i++) {
            dp[arr[i]] = max(dp[arr[i]], 1 + dp[arr[i] - dif]);
            ans = max(ans, dp[arr[i]]);
        }
        
        return ans;
    }
};