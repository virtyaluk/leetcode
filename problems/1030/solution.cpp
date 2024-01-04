class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans.push_back({i, j});
            }
        }
        
        sort(begin(ans), end(ans), [&](const vector<int>& lhs, const vector<int>& rhs) {
            return abs(lhs.front() - rCenter) + abs(lhs.back() - cCenter) < abs(rhs.front() - rCenter) + abs(rhs.back() - cCenter);
        });
        
        return ans;
    }
};