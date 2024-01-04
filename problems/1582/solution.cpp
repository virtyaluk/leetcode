class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0,
            m = size(mat),
            n = size(mat.front());
        vector<int> rows(m),
            cols(n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 and rows[i] == 1 and cols[j] == 1) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};