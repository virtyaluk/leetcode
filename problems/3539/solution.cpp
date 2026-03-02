const int MOD = 1e9 + 7;

class Solution {
private:
    long long quickmul(long long x, long long y, long long mod) {
        long long ans = 1,
            cur = x % mod;

        while (y) {
            if (y & 1) {
                ans = ans * cur % mod;
            }

            y >>= 1;
            cur = cur * cur % mod;
        }

        return ans;
    }
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = size(nums);
        long long ans = 0;
        vector<long long> fac(m + 1, 1),
            ifac(m + 1, 1);
        vector numsPower(n, vector<long long>(m + 1, 1));
        vector dp(n, vector(m + 1, vector(m * 2 + 1, vector<long long>(k + 1))));

        for (int i = 1; i <= m; i++) {
            fac[i] = fac[i - 1] * i % MOD;
        }

        for (int i = 2; i <= m; i++) {
            ifac[i] = quickmul(i, MOD - 2, MOD);
        }

        for (int i = 2; i <= m; i++) {
            ifac[i] = ifac[i - 1] * ifac[i] % MOD;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                numsPower[i][j] = numsPower[i][j - 1] * nums[i] % MOD;
            }
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j][j][0] = numsPower[0][j] * ifac[j] % MOD;
        }

        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= m * 2; p++) {
                    for (int q = 0; q <= k; q++) {
                        int q2 = p % 2 + q;

                        if (q2 > k) {
                            break;
                        }

                        for (int r = 0; r + j <= m; r++) {
                            int p2 = p / 2 + r;
                            dp[i + 1][j + r][p2][q2] += dp[i][j][p][q] * numsPower[i + 1][r] % MOD * ifac[r] % MOD;
                            dp[i + 1][j + r][p2][q2] %= MOD;
                        }
                    }
                }
            }
        }

        for (int p = 0; p <= m * 2; p++) {
            for (int q = 0; q <= k; q++) {
                if (__builtin_popcount(p) + q == k) {
                    ans = (ans + dp[n - 1][m][p][q] * fac[m] % MOD) % MOD;
                }
            }
        }

        return ans;
    }
};