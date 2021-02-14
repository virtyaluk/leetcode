class Solution {
public:
    int pathSum(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> g(5, vector<int>(8));
        
        for (const int& num: nums) {
            int d = num / 100, p = (num % 100) / 10 - 1, v = num % 10;
            g[d][p] = v + g[d - 1][p / 2];
        }
        
        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < 8; j++) {
                if (i == 4 || g[i][j] && !g[i + 1][j * 2] && !g[i + 1][j * 2 + 1]) {
                    ans += g[i][j];
                }
            }
        }
        
        return ans;
    }
};