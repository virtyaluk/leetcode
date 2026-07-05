class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = size(nums);
        vector<int> dp(n, INT_MIN);

        function<int(int)> dfs = [&](int i) -> int {
            if (i == n - 1) {
                return 0;
            }

            if (dp[i] != INT_MIN) {
                return dp[i];
            }

            int ans = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    ans = max(ans, dfs(j) + 1);
                }
            }

            return dp[i] = ans;
        };

        int ans = dfs(0);

        return ans < 0 ? -1 : ans;
    }
};