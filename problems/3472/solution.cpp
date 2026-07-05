class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = size(s);
        unordered_map<int, bool> cachePal;
        unordered_map<int, int> cacheDfs;
        function<int(int)> dfs;
        auto pal = [&](int i, int j) -> bool {
            if (cachePal.count(i * n + j) > 0) {
                return cachePal[i * n + j];
            }

            cachePal[i * n + j] = false;

            if (j > n) {
                return false;
            }

            for (int l = i, r = j - 1; l < r; l++, r--) {
                if (s[l] != s[r]) {
                    return false;
                }
            }

            cachePal[i*n+j] = true;

            return true;
        };
        dfs = [&](int i) -> int {
            if (cacheDfs.count(i) > 0) {
                return cacheDfs[i];
            }

            if (i + k > n) {
                cacheDfs[i] = 0;

                return 0;
            }

            int m = dfs(i + 1);

            if (pal(i, i + k)) {
                m = max(m, 1 + dfs(i + k));
            }

            if (pal(i, i + k + 1)) {
                m = max(m, 1 + dfs(i + k + 1));
            }

            cacheDfs[i] = m;

            return m;
        };

        return dfs(0);
    }
};