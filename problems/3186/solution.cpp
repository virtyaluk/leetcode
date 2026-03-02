class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long ans = 0,
            mx = 0;;
        map<int, int> freq;
        vector<pair<int, int>> vp = {{-1e9, 0}};

        for (const int& p: power) {
            freq[p]++;
        }

        for (auto& p: freq) {
            vp.push_back(p);
        }

        int n = size(vp);
        vector<long long> dp(n);

        for (int i = 1, j = 1; i < n; i++) {
            while (j < i and vp[j].first < vp[i].first - 2) {
                mx = max(mx, dp[j]);
                j++;
            }

            dp[i] = mx + 1ll * vp[i].first * vp[i].second;
        }

        for (int i = 1; i < n; i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};