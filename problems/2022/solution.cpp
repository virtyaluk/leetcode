class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != size(original)) {
            return {};
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0, k = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = original[k++];
            }
        }
        
        return ans;
    }
};