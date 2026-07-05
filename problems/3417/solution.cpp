class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;

        for (int i = 0; i < size(grid); i++) {
            vector<int> cur;

            for (int j = 0; j < size(grid[i]); j++) {
                if ((i % 2 == 0 and j % 2 == 0) or (i % 2 != 0 and j % 2 != 0)) {
                    cur.push_back(grid[i][j]);
                }
            }

            if (i % 2 != 0) {
                reverse(begin(cur), end(cur));
            }

            ans.insert(end(ans), begin(cur), end(cur));
        }

        return ans;
    }
};