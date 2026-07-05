class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = size(matrix);
        vector<unordered_set<int>> rows(n),
            cols(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rows[i].insert(matrix[i][j]);
                cols[j].insert(matrix[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (size(rows[i]) != n or size(cols[i]) != n) {
                return false;
            }
        }

        return true;
    }
};