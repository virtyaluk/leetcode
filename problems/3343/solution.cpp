const int MOD = 1e9 + 7;

class Solution {
public:
    int countBalancedPermutations(string num) {
        int total = 0,
            n = size(num);
        vector<int> freq(10);

        for (const char& ch: num) {
            freq[ch - '0']++;
            total += (ch - '0');
        }

        if (total % 2 != 0) {
            return 0;
        }

        int target = total / 2,
            maxOdd = (n + 1) / 2,
            pSum = 0,
            totalSum = 0;
        vector<vector<long long>> comb(maxOdd + 1, vector<long long>(maxOdd + 1)),
            memo(target + 1, vector<long long>(maxOdd + 1));

        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        memo[0][0] = 1;

        for (int i = 0; i <= 9; i++) {
            pSum += freq[i];
            totalSum += i * freq[i];

            for (int oddCnt = min(pSum, maxOdd); oddCnt >= max(0, pSum - (n - maxOdd)); oddCnt--) {
                int evenCnt = pSum - oddCnt;

                for (int cur = min(totalSum, target); cur >= max(0, totalSum - target); cur--) {
                    long long ans = 0;

                    for (int j = max(0, freq[i] - evenCnt); j <= min(freq[i], oddCnt) and i * j <= cur; j++) {
                        long long ways = comb[oddCnt][j] * comb[evenCnt][freq[i] - j] % MOD;
                        ans = (ans + ways * memo[cur - i * j][oddCnt - j] % MOD) % MOD;
                    }

                    memo[cur][oddCnt] = ans % MOD;
                }
            }
        }

        return memo[target][maxOdd];
    }
};