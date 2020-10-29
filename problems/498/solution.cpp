class Solution {
public:
    vector<int> findDiagonalOrder1(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.size() > 0 ? matrix[0].size() : 0;
        map<int, vector<int>> store;
        vector<int> ans;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                store[i + j].push_back(matrix[i][j]);
            }
        }
        
        for (auto& [idx, ar]: store) {
            if (idx % 2 != 0) {
                ans.insert(ans.end(), ar.begin(), ar.end());
            } else {
                ans.insert(ans.end(), ar.rbegin(), ar.rend());
            }
        }
        
        return ans;
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix.back());
        bool dir = false;
        vector<int> ans;
        
        for (int i = 0; i <= m + n - 2; i++) {
            int j = i;
            
            while (j >= 0) {
                int x = j, y = i - j;
                
                if (dir) {
                    swap(x, y);
                }
                
                if (0 <= x and x < m and 0 <= y and y < n) {
                    ans.push_back(matrix[x][y]);
                }
                
                j--;
            }
            
            dir = !dir;
        }
        
        return ans;
    }
};