class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0, n = mat.size(), i = 0, j = n - 1;
        
        for (int r = 0; r < n; r++) {
            if (i == j) {
                ans += mat[r][i];
            } else {
                ans += mat[r][i] + mat[r][j];
            }
            
            i++;
            j--;
        }
        
        return ans;
    }
};