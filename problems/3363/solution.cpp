class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = size(fruits),
            ans = 0;
        function<int()> dp = [&]() -> int {
            vector<int> prev(n, INT_MIN),
                cur(n, INT_MIN);
            prev[n - 1] = fruits.front().back();

            for (int i = 1; i < n - 1; i++) {
                for (int j = max(n - 1 - i, i + 1); j < n; j++) {
                    int best = prev[j];

                    if (j - 1 >= 0) {
                        best = max(best, prev[j - 1]);
                    }

                    if (j + 1 < n) {
                        best = max(best, prev[j + 1]);
                    }

                    cur[j] = best + fruits[i][j];
                }

                swap(prev, cur);
            }
            
            return prev[n - 1];
        };
        
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        };

        ans += dp();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(fruits[i][j], fruits[j][i]);
            }
        }

        ans += dp();

        return ans;
    }
};