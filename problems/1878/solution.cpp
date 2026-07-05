class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = size(grid),
            m = size(grid.front());
        set<int> s;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s.insert(grid[i][j]);

                for (int len = 1; i + 2 * len < n and j - len >= 0 and j + len < m; len++) {
                    int curSum = 0;

                    for (int idx = 0; idx < len; idx++) {
                        curSum += grid[i + idx][j + idx];
                    }

                    for (int idx = 0; idx < len; idx++) {
                        curSum += grid[i + len + idx][j + len - idx];
                    }

                    for (int idx = 0; idx < len; idx++) {
                        curSum += grid[i + 2 * len - idx][j - idx];
                    }

                    for (int idx = 0; idx < len; idx++) {
                        curSum += grid[i + len - idx][j - len + idx];
                    }

                    s.insert(curSum);
                }
            }
        }

        vector<int> ans(rbegin(s), rend(s));

        if (size(ans) > 3) {
            ans.resize(3);
        }

        return ans;
    }
};