class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans = {0, 0};
        unordered_map<int, int> um;
        
        for (int row = 0; row < size(mat); row++) {
            for (int col = 0; col < size(mat.back()); col++) {
                um[row] += mat[row][col] == 1;
            }
        }
        
        for (int row = 0; row < size(mat); row++) {
            if (um[row] > ans.back()) {
                ans = {row, um[row]};
            }
        }
        
        return ans;
    }
};