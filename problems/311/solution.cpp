class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        int m = size(a),
            n = size(a.back()),
            p = size(b.back());
        vector<vector<int>> ans(m, vector<int>(p));
        
        for (int j = 0; j < n; j++) {
            vector<int> rowB;
            
            for (int i = 0; i < p; i++) {
                if (b[j][i]) {
                    rowB.push_back(i);
                }
            }
            
            for (int i = 0; i < m; i++) {
                if (a[i][j]) {
                    for (int k: rowB) {
                        ans[i][k] += b[j][k] * a[i][j];
                    }
                }
            }
        }
        
        return ans;
    }
};