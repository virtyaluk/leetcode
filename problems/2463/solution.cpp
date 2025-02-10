class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int> factPos;
        
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));
        
        for (const vector<int>& f: factory) {
            for (int i = 0; i < f[1]; i++) {
                factPos.push_back(f[0]);
            }
        }
        
        int r = size(robot),
            f = size(factPos);
        vector<vector<long long>> dp(r + 1, vector<long long>(f + 1));
        
        for (int i = 0; i < r; i++) {
            dp[i][f] = 1e12;
        }
        
        for (int i = r - 1; i >= 0; i--) {
            for (int j = f - 1; j >= 0; j--) {
                long long assign = abs(robot[i] - factPos[j]) + dp[i + 1][j + 1],
                    skip = dp[i][j + 1];
                dp[i][j] = min(assign, skip);
            }
        }
        
        return dp.front().front();
    }
};