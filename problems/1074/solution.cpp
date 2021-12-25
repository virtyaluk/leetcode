class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0, m = matrix.size(), n = matrix.back().size();
        vector<vector<int>> ps(m + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        
        for (int startRow = 1; startRow <= m; startRow++) {
            for (int endRow = startRow; endRow <= m; endRow++) {
                unordered_map<int, int> um = {{0, 1}};
                
                for (int col = 1; col <= n; col++) {
                    int sum = ps[endRow][col] - ps[startRow - 1][col];
                    
                    ans += um[sum - target];
                    um[sum]++;
                }
            }
        }
        
        return ans;
    }
};

/*
  1  -1
 -1   1
 
  1   0
  0   0
*/