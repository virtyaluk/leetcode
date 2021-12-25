class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        return maxSumDivK(nums, 3);
    }
    
    int maxSumDivK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(k, INT_MIN);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1], mod = nums[i - 1] % k;
            vector<int> newDp(k);
            
            for (int j = 0; j < k; j++) {
                newDp[j] = max(dp[j], dp[(j + mod) % k] + num);
            }
            
            dp = newDp;
        }
        
        return dp[0];
    }
    
    int maxSumDivThree1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3));
        dp[0][1] = dp[0][2] = INT_MIN;
        
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            
            if (num % 3 == 0) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + num);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + num);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][2] + num);
            } else if (num % 3 == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + num);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + num);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + num);
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + num);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + num);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + num);
            }
        }
        
        return dp[n][0];
    }
};