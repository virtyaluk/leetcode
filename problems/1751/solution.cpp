class Solution {
private:
    vector<vector<int>> dp;

    int dfs(int curIdx, int cnt, int prev, vector<vector<int>>& events, int k) {
        if (curIdx == size(events) or cnt == k) {
            return 0;
        }

        if (prev >= events[curIdx].front()) {
            return dfs(curIdx + 1, cnt, prev, events, k);
        }

        if (dp[cnt][curIdx] != -1) {
            return dp[cnt][curIdx];
        }

        int ans = max(
            dfs(curIdx + 1, cnt, prev, events, k),
            dfs(curIdx + 1, cnt + 1, events[curIdx][1], events, k) + events[curIdx][2]
        );

        dp[cnt][curIdx] = ans;

        return ans;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));
        dp = vector<vector<int>>(k + 1, vector<int>(size(events), -1));

        return dfs(0, 0, -1, events, k);
    }
};