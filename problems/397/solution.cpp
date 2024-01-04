class Solution {
private:
    int dfs(unordered_map<unsigned int, int>& dp, unsigned int n) {
        if (n == 1) {
            return 0;
        }
        
        if (not dp.count(n)) {
            if (n % 2) {
                dp[n] = 1 + min(dfs(dp, n - 1), dfs(dp, n + 1));
            } else {
                dp[n] = 1 + dfs(dp, n / 2);
            }
        }
        
        return dp[n];
    }
public:
    int integerReplacement(int n) {
        unordered_map<unsigned int, int> dp;
        
        return dfs(dp, n);
    }
};