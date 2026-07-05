class Solution {
private:
    bool canRemove(int r1, int c1, int r2, int c2, int i, int j) {
        int rows = r2 - r1 + 1,
            cols = c2 - c1 + 1;
        
        if (rows == 1) {
            return j == c1 or j == c2;
        }

        if (cols == 1) {
            return i == r1 or i == r2;
        }

        return true;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = size(grid),
            m = size(grid.front());
        vector<long long> prefRow(n, 0),
            prefCol(m, 0);
        map<long long, vector<pair<int, int>>> mp;

        for (int i = 0; i < n; i++) {
            long long val = 0;

            for (int j = 0; j < m; j++) {
                val += grid[i][j];
                mp[grid[i][j]].push_back({i, j});
            }

            prefRow[i] = val + (i ? prefRow[i - 1] : 0);
        }

        for (int j = 0; j < m; j++) {
            long long val = 0;

            for (int i = 0; i < n; i++) {
                val += grid[i][j];
            }

            prefCol[j] = val + (j ? prefCol[j - 1] : 0);
        }

        long long total = prefRow.back();

        for (int i = 0; i < n - 1; i++) {
            long long top = prefRow[i],
                bottom = total - top;
            
            if (top == bottom) {
                return true;
            }

            long long diff = abs(top - bottom);

            if (not mp.count(diff)) {
                continue;
            }

            if (top > bottom) {
                for (auto& p: mp[diff]) {
                    int x = p.first,
                        y = p.second;
                    
                    if (x <= i and canRemove(0, 0, i, m - 1, x, y)) {
                        return true;
                    }
                }
            } else {
                for (auto &p: mp[diff]) {
                    int x = p.first,
                        y = p.second;

                    if (x > i and canRemove(i + 1, 0, n - 1, m - 1, x, y)) {
                        return true;
                    }
                }
            }
        }

        for (int j = 0; j < m - 1; j++) {
            long long left = prefCol[j],
                right = total - left;
            
            if (left == right) {
                return true;
            }

            long long diff = abs(left - right);

            if (not mp.count(diff)) {
                continue;
            }

            if (left > right) {
                for (auto &p: mp[diff]) {
                    int x = p.first,
                        y = p.second;
                    
                    if (y <= j and canRemove(0, 0, n - 1, j, x, y)) {
                        return true;
                    }
                }
            } else {
                for (auto &p: mp[diff]) {
                    int x = p.first,
                        y = p.second;
                    
                    if (y > j and canRemove(0, j + 1, n - 1, m - 1, x, y)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};