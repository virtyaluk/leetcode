class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        auto&& r = restrictions;
        r.push_back({1, 0});

        sort(begin(r), end(r));

        if (r.back().front() != n) {
            r.push_back({n, n - 1});
        }

        int m = size(r),
            ans = 0;
        
        for (int i = 1; i < m; i++) {
            r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
        }

        for (int i = m - 2; i >= 0; i--) {
            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
        }

        for (int i = 0; i < m - 1; i++) {
            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
            ans = max(ans, best);
        }

        return ans;
    }
};