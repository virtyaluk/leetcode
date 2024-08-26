class neighborSum {
private:
    unordered_map<int, vector<pair<int, int>>> um;
    vector<vector<int>> g;
    
    int getVal(int i, int j) {
        if (i < 0 or i >= size(g) or j < 0 or j >= size(g.front())) {
            return 0;
        }
        
        return g[i][j];
    }
public:
    neighborSum(vector<vector<int>>& grid) {
        g = grid;
        
        for (int i = 0; i < size(g); i++) {
            for (int j = 0; j < size(g[i]); j++) {
                um[g[i][j]].push_back({i, j});
            }
        }
    }
    
    int adjacentSum(int value) {
        int ans = 0;
        
        for (auto [i, j]: um[value]) {
            ans += getVal(i - 1, j);
            ans += getVal(i + 1, j);
            ans += getVal(i, j - 1);
            ans += getVal(i, j + 1);
        }
        
        return ans;
    }
    
    int diagonalSum(int value) {
        int ans = 0;
        
        for (auto [i, j]: um[value]) {
            ans += getVal(i - 1, j - 1);
            ans += getVal(i - 1, j + 1);
            ans += getVal(i + 1, j - 1);
            ans += getVal(i + 1, j + 1);
        }
        
        return ans;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */