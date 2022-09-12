const int MOD = 1e9 + 7;

class Solution {
private:
    long long dfs(vector<vector<long long>>& dp, vector<int>& nums) {
        int n = size(nums);
        
        if (n < 3) {
            return 1;
        }
        
        vector<int> leftNodes, rightNodes;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                leftNodes.push_back(nums[i]);
            } else {
                rightNodes.push_back(nums[i]);
            }
        }
        
        long long leftWays = dfs(dp, leftNodes) % MOD,
            rightWays = dfs(dp, rightNodes) % MOD;
        
        return (((leftWays * rightWays) % MOD) * dp[n - 1][size(leftNodes)]) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = size(nums);
        vector<vector<long long>> dp(n + 1);
        
        for (int i = 0; i < n + 1; i++) {
            dp[i] = vector<long long>(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
        
        return (dfs(dp, nums) - 1) % MOD;
    }
};