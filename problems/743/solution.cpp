class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        vector<int> dists(n + 1, INT_MAX);
        unordered_map<int, unordered_map<int, int>> g;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dists[k] = 0;
        pq.push({0, k});
        
        for (const vector<int>& time: times) {
            int u = time[0],
                v = time[1],
                w = time[2];
            
            g[u][v] = w;
        }
        
        while (not empty(pq)) {
            auto [ignore, u] = pq.top();
            pq.pop();
            
            for (auto [v, w]: g[u]) {
                if (dists[v] > dists[u] + w) {
                    dists[v] = min(dists[v], dists[u] + w);
                    pq.push({dists[v], v});
                }
            }
        }
        
        ans = *max_element(begin(dists) + 1, end(dists));
        
        return ans == INT_MAX ? -1 : ans;
    }
};