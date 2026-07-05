class Solution {
private:
    vector<int> dp;

    void dfs(vector<int>& arr, int id, int d, int n) {
        if (dp[id] != -1) {
            return;
        }

        dp[id] = 1;

        for (int i = id - 1; i >= 0 and id - i <= d and arr[id] > arr[i]; i--) {
            dfs(arr, i, d, n);

            dp[id] = max(dp[id], dp[i] + 1);
        }

        for (int i = id + 1; i < n and i - id <= d and arr[id] > arr[i]; i++) {
            dfs(arr, i, d, n);

            dp[id] = max(dp[id], dp[i] + 1);
        }
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = size(arr);

        dp.resize(n, -1);

        for (int i = 0; i < n; i++) {
            dfs(arr, i, d, n);
        }

        return *max_element(begin(dp), end(dp));
    }
};