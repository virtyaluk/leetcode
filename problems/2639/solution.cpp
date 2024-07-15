class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = size(grid),
            n = size(grid.front());
        vector<int> ans(n, 0);
        
        for (const vector<int>& row: grid) {
            for (int i = 0; i < size(row); i++) {
                ans[i] = max(ans[i], (int) size(to_string(row[i])));
            }
        }
        
        return ans;
    }
};