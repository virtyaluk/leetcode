class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = size(grid), n = size(grid.back()), ans = 0, counter = 2;
        unordered_map<int, int> lands = {{0, 0}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, lands, i, j, counter++);
                    ans = max(ans, lands[counter - 1]);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neislands = {
                        get(grid, i + 1, j),
                        get(grid, i - 1, j),
                        get(grid, i, j + 1),
                        get(grid, i, j - 1)
                    };
    
                    ans = max(ans, accumulate(begin(neislands), end(neislands), 1, [&](int lhs, int rhs) {
                        return lhs + lands[rhs];
                    }));
                }
            }
        }
        
        return ans;
    }
    
    int get(const vector<vector<int>>& g, int x, int y) {
        if (x < 0 or x >= size(g) or y < 0 or y >= size(g.back())) {
            return 0;
        }
        
        return g[x][y];
    }
    
    void dfs(vector<vector<int>>& g, unordered_map<int, int>& l, int x, int y, int c) {
        int m = size(g), n = size(g.back());
        
        if (x < 0 or x >= m or y < 0 or y >= n or g[x][y] != 1) {
            return;
        }
        
        g[x][y] = c;
        l[c]++;
        
        dfs(g, l, x + 1, y, c);
        dfs(g, l, x - 1, y, c);
        dfs(g, l, x, y + 1, c);
        dfs(g, l, x, y - 1, c);
    }
};

/*
1 0
0 1

*/