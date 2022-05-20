class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mt) {
        int m = mt.size(), n = mt[0].size();
        vector<int> ans, mins(m, INT_MAX), maxs(n, INT_MIN);
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                mins[r] = min(mins[r], mt[r][c]);
                maxs[c] = max(maxs[c], mt[r][c]);
            }
        }
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mt[r][c] == mins[r] && mt[r][c] == maxs[c]) {
                    ans.push_back(mt[r][c]);
                }
            }
        }
        
        return ans;
    }
};