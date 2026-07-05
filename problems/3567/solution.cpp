class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = size(grid),
            n = size(grid.front());
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                vector<int> kg;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        kg.push_back(grid[x][y]);
                    }
                }

                int km = INT_MAX;

                sort(begin(kg), end(kg));

                for (int t = 1; t < size(kg); t++) {
                    if (kg[t] == kg[t - 1]) {
                        continue;
                    }

                    km = min(km, kg[t] - kg[t - 1]);
                }

                if (km != INT_MAX) {
                    ans[i][j] = km;
                }
            }
        }

        return ans;
    }
};