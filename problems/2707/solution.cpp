class Solution {
private:
    int dfs(unordered_map<string, int>& um, vector<int>& dp, string& s, int idx) {
        if (idx >= size(s)) {
            return 0;
        }

        int ans = INT_MAX;

        if (dp[idx] != -1) {
            return dp[idx];
        }

            ans = 1 + dfs(um, dp, s, idx + 1);
            string k = "";

            for (int i = idx; i < size(s); i++) {
                k += s[i];

                if (um[k]) {
                    ans = min(ans, dfs(um, dp, s, i + 1));
                }
            }

        return dp[idx] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_map<string, int> um;
        vector<int> dp(size(s), -1);

        for (auto w: dict) {
            um[w]++;
        }

        return dfs(um, dp, s, 0);
    }
};