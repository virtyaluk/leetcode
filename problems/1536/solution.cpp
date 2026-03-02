class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = size(grid),
            ans = 0;
        vector<int> cnt(n);

        for (int i = 0; i < n; i++) {
            int j = n - 1;

            while (j >= 0 and grid[i][j] == 0) {
                j--;
            }

            cnt[i] = (n - j) - 1;
        }

        for (int i = 0; i < n; i++) {
            int need = n - (i + 1);

            if (cnt[i] >= need) {
                continue;
            }

            int idx = -1;

            for (int j = i + 1; j < n; j++) {
                if (cnt[j] >= need) {
                    idx = j;

                    break;
                }
            }

            if (idx == -1) {
                return -1;
            }

            while (idx > i) {
                swap(cnt[idx], cnt[idx - 1]);

                ans++;
                idx--;
            }
        }

        return ans;
    }
};