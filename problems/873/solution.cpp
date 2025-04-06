class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0,
            n = size(arr);
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_map<int, int> um;

        for (int i = 0; i < size(arr); i++) {
            um[arr[i]] = i;

            for (int j = 0; j < i; j++) {
                int dif = arr[i] - arr[j];

                if (dif < arr[j] and um.count(dif)) {
                    dp[j][i] = dp[um[dif]][j] + 1;
                } else {
                    dp[j][i] = 2;
                }

                ans = max(ans, dp[j][i]);
            }
        } 

        return ans > 2 ? ans : 0;
    }
};