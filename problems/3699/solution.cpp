constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp0(m, 0),
            dp1(m, 0),
            sum0(m + 1, 0),
            sum1(m + 1, 0);
        auto op = [](int acc, int x) { return (acc + x) % MOD; };

        for (int i = 0; i < m; i++) {
            dp0[i] = dp1[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum0[j + 1] = (sum0[j] + dp0[j]) % MOD;
                sum1[j + 1] = (sum1[j] + dp1[j]) % MOD;
            }

            for (int j = 0; j < m; j++) {
                dp0[j] = (sum1[m] - sum1[j + 1] + MOD) % MOD;
                dp1[j] = sum0[j];
            }
        }

 
        auto ans0 = reduce(begin(dp0), end(dp0), 0, op);
        auto ans1 = reduce(begin(dp1), end(dp1), 0, op);

        return (ans0 + ans1) % MOD;
    }
};