class Solution {
private:
    void dfs(vector<vector<int>>& g, int x, int y, int dir) {
        if (x < 0 or x >= size(g) or y < 0 or y >= size(g[x]) or g[x][y] == 2 or g[x][y] == 3) {
            return;
        }
        
        g[x][y] = 1;
        
        if (dir == 0) {
            dfs(g, x - 1, y, dir);
        }
        
        if (dir == 1) {
            dfs(g, x + 1, y, dir);
        }
        
        if (dir == 2) {
            dfs(g, x, y - 1, dir);
        }
        
        if (dir == 3) {
            dfs(g, x, y + 1, dir);
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = 0;
        vector<vector<int>> g(m, vector<int>(n));
        
        for (const vector<int>& g1: guards) {
            g[g1.front()][g1.back()] = 2;
        }
        
        for (const vector<int>& w: walls) {
            g[w.front()][w.back()] = 3;
        }
        
        for (const vector<int>& g1: guards) {
            dfs(g, g1.front() - 1, g1.back(), 0);
            dfs(g, g1.front() + 1, g1.back(), 1);
            dfs(g, g1.front(), g1.back() - 1, 2);
            dfs(g, g1.front(), g1.back() + 1, 3);
        }
        
        for (const vector<int>& row: g) {
            for (const int& cell: row) {
                if (not cell) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};