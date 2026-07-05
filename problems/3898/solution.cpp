class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = size(matrix);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int deg = 0;

            for (int j = 0; j < n; j++) {
                deg += matrix[i][j] == 1;
            }

            ans[i] = deg;
        }

        return ans;
    }
};