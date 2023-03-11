class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = size(mat);
        vector<bool> ans(4, true);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[0] = ans[0] and mat[i][j] == target[j][n - 1 - i]; // 90deg rot
                ans[1] = ans[1] and mat[i][j] == target[n - 1 - j][i]; // 270deg rot
                ans[2] = ans[2] and mat[i][j] == target[n - 1 - i][n - 1 - j]; // 180deg rot
                ans[3] = ans[3] and mat[i][j] == target[i][j];
            }
        }
        
        return ans[0] or ans[1] or ans[2] or ans[3];
    }
};