const int MOD = 1e9 + 7;

class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = size(word),
            cnt = 1,
            ans = 1;
        vector<int> freq,
            f(k),
            g(k, 1);
        f[0] = 1;

        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                cnt++;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }

        freq.push_back(cnt);

        for (const int& f: freq) {
            ans = static_cast<long long>(ans) * f % MOD;
        }

        if (size(freq) >= k) {
            return ans;
        }

        for (int i = 0; i < size(freq); i++) {
            vector<int> newFreq(k),
                newG(k);

            for (int j = 1; j < k; j++) {
                newFreq[j] = g[j - 1];

                if (j - freq[i] - 1 >= 0) {
                    newFreq[j] = (newFreq[j] - g[j - freq[i] - 1] + MOD) % MOD;
                }
            }

            newG[0] = newFreq[0];

            for (int j = 1; j < k; j++) {
                newG[j] = (newG[j - 1] + newFreq[j]) % MOD;
            }

            f = move(newFreq);
            g = move(newG);
        }

        return (ans - g[k - 1] + MOD) % MOD;
    }
};