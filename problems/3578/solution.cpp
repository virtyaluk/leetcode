const int MOD = 1e9 + 7;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = size(nums);
        vector<long long> dp(n + 1),
            prefix(n + 1);
        multiset<int> cnt;
        dp.front() = 1;
        prefix.front() = 1;

        for (int i = 0, j = 0; i < n; i++) {
            cnt.emplace(nums[i]);

            while (j <= i and *cnt.rbegin() - *cnt.begin() > k) {
                cnt.erase(cnt.find(nums[j]));
                j++;
            }

            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1]: 0) + MOD) % MOD;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % MOD;
        }

        return dp.back();
    }
};