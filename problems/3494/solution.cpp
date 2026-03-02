class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = size(skill),
            m = size(mana);
        vector<long long> dp(n);

        for (int j = 0; j < m; j++) {
            long long cur = 0;

            for (int i = 0; i < n; i++) {
                cur = max(cur, dp[i]) + skill[i] * mana[j];
            }

            dp.back() = cur;

            for (int i = n - 2; i >= 0; i--) {
                dp[i] = dp[i + 1] - skill[i + 1] * mana[j];
            }
        }

        return dp.back();
    }
};