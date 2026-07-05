class Solution {
private:
    int getDist(int x, int y) {
        int x1 = x / 6,
            y1 = x % 6,
            x2 = y / 6,
            y2 = y % 6;
        
        return abs(x1 - x2) + abs(y1 - y2);
    }
public:
    int minimumDistance(string word) {
        int n = size(word);
        vector<vector<int>> dp(n, vector<int>(26, INT_MAX >> 1));
        
        fill(begin(dp.front()), end(dp.front()), 0);

        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A',
                prev = word[i - 1] - 'A',
                d = getDist(prev, cur);
            
            for (int j = 0; j < 26; j++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + d);

                if (prev == j) {
                    for (int k = 0; k < 26; k++) {
                        int d0 = getDist(k, cur);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + d0);
                    }
                }
            }
        }

        return *min_element(begin(dp.back()), end(dp.back()));
    }
};