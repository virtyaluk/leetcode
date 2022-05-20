class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxDiagonals = 0;
        vector<int> ans;
        unordered_map<int, vector<int>> diagonals;
        
        for (int i = 0; i < size(nums); i++) {
            for (int j = 0; j < size(nums[i]); j++) {
                diagonals[i + j].push_back(nums[i][j]);
                maxDiagonals = max(maxDiagonals, i + j);
            }
        }
        
        for (int i = 0; i <= maxDiagonals; i++) {
            ans.insert(end(ans), rbegin(diagonals[i]), rend(diagonals[i]));
        }
        
        return ans;
    }
};