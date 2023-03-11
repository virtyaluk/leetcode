class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {
        return (grid.size() + grid.back().size() - 1) % 2 == 0;
    }
};