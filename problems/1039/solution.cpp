class Solution {
private:
    int dfs(unordered_map<int, int>& dp, vector<int>& values, int i, int j, const int& n) {
        if (i + 2 > j) {
            return 0;
        }

        if (i + 2 == j) {
            return values[i] * values[i + 1] * values[j];
        }

        int idx = i * n + j;

        if (not dp.count(idx)) {
            int ans = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                ans = min(ans, values[i] * values[k] * values[j] + dfs(dp, values, i, k, n) + dfs(dp, values, k, j, n));
            }

            dp[idx] = ans;
        }

        return dp[idx];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = size(values);
        unordered_map<int, int> dp;

        return dfs(dp, values, 0, n - 1, n);
    }
};