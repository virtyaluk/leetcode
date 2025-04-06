const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> paths(n, 0);
        vector<long long> times(n, LLONG_MAX);
        vector<vector<pair<int, int>>> g(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        for (const vector<int>& r: roads) {
            g[r.front()].push_back({r[1], r.back()});
            g[r[1]].push_back({r.front(), r.back()});
        }

        times[0] = 0;
        paths[0] = 1;
        pq.push({0, 0});

        while (not empty(pq)) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > times[node]) {
                continue;
            }

            for (auto [nextNode, nextTime]: g[node]) {
                if (time + nextTime < times[nextNode]) {
                    times[nextNode] = time + nextTime;
                    paths[nextNode] = paths[node];
                    pq.push({times[nextNode], nextNode});
                } else if (time + nextTime == times[nextNode]) {
                    paths[nextNode] = (paths[nextNode] + paths[node]) % MOD;
                }
            }
        }

        return paths.back();
    }
};