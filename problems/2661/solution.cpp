class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = size(mat),
            n = size(mat.front());
        vector<int> rows(m),
            cols(n);
        unordered_map<int, pair<int, int>> um;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                um[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < size(arr); i++) {
            auto [row, col] = um[arr[i]];
            rows[row]++;
            cols[col]++;

            if (rows[row] == n or cols[col] == m) {
                return i;
            }
        }

        return -1;
    }
};