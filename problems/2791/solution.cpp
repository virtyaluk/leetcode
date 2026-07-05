class Solution {
private:
    int helper(vector<int>& dp, vector<int>& parent, string& s, int i) {
        if (i > 0 and dp[i] == 0) {
            dp[i] = helper(dp, parent, s, parent[i]) ^ (1 << (s[i] - 'a'));
        }

        return dp[i];
    }
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = size(parent);
        long long ans = 0;
        vector<int> dp(n);
        unordered_map<int, int> count;

        for (int i = 0; i < n; i++) {
            int mask = helper(dp, parent, s, i);

            for (int j = 0; j < 26; j++) {
                ans += count.count(mask ^ (1 << j)) ? count[mask ^ (1 << j)] : 0;
            }

            ans += count[mask]++;
        }

        return ans;
    }
};