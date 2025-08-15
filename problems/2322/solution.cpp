class Solution {
private:
    int calc(int p1, int p2, int p3) {
        return max(p1, max(p2, p3)) - min(p1, min(p2, p3));
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = size(nums),
            cnt = 0,
            ans = INT_MAX;
        vector<int> sum(n),
            in(n),
            out(n);
        vector<vector<int>> g(n);
        function<void(int, int)> dfs = [&](int x, int fa) {
            in[x] = cnt++;
            sum[x] = nums[x];

            for (const int& y: g[x]) {
                if (y == fa) {
                    continue;
                }

                dfs(y, x);
                sum[x] ^= sum[y];
            }

            out[x] = cnt;
        };
    
        for (const vector<int>& e: edges) {
            g[e.front()].push_back(e.back());
            g[e.back()].push_back(e.front());
        }

        dfs(0, -1);

        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (in[v] > in[u] and in[v] < out[u]) {
                    ans = min(ans, calc(sum[0] ^ sum[u], sum[u] ^ sum[v], sum[v]));
                } else if (in[u] > in[v] and in[u] < out[v]) {
                    ans = min(ans, calc(sum[0] ^ sum[v], sum[v] ^ sum[u], sum[u]));
                } else {
                    ans = min(ans, calc(sum[0] ^ sum[u] ^ sum[v], sum[u], sum[v]));
                }
            }
        }

        return ans;
    }
};