class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> um;

        for (auto p: pick) {
            um[p[0]][p[1]]++;
        }

        for (auto [pi, balls]: um) {
            int cur = 0;

            for (auto [_, cnt]: balls) {
                cur = max(cur, cnt);
            }

            ans += cur > pi;
        }

        return ans;
    }
};