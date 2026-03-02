#define ll long long

class Solution {
private:
    void helper(unordered_map<ll, vector<pair<ll, ll>>>& g, vector<ll>& dis, int src) {
        dis[src] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.push({0, src});

        while (not empty(pq)) {
            auto [w, node] = pq.top();
            pq.pop();

            if (dis[node] < w) {
                continue;
            }

            for (auto& [v, w1]: g[node]) {
                if (dis[v] > dis[node] + w1) {
                    dis[v] = dis[node] + w1;
                    pq.push({dis[v], v});
                }
            }
        }
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        ll ans = LLONG_MAX;
        unordered_map<ll, vector<pair<ll, ll>>> um1, um2;
        vector<ll> src1dis(n, LLONG_MAX),
            src2dis(n, LLONG_MAX),
            distDest(n, LLONG_MAX);

        for (const vector<int>& e: edges) {
            um1[e[0]].push_back({e[1], e[2]});
            um2[e[1]].push_back({e[0], e[2]});
        }

        helper(um1, src1dis, src1);
        helper(um1, src2dis, src2);
        helper(um2, distDest, dest);

        for (int i = 0; i < n; i++) {
            if (src1dis[i] != LLONG_MAX and src2dis[i] != LLONG_MAX and distDest[i] != LLONG_MAX) {
                ans = min(ans, src1dis[i] + src2dis[i] + distDest[i]);
            }
        }

        return ans == LONG_MAX ? -1 : ans;
    }
};