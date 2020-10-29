class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = 0, n = wall.size();
        unordered_map<int, int> um;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0, start = 0; j < wall[i].size() - 1; j++) {
                start += wall[i][j];
                um[start]++;
                
                ans = max(ans, um[start]);
            }
        }
        
        // for (auto &[ignore, freq]: um) {
        //     ans = max(ans, freq);
        // }
        
        return n - ans;
    }
};