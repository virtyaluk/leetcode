class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if (n < 2) {
            return 1;
        }
        
        int ans = 0;
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        vector<long long> valuesll(begin(values), end(values));
        queue<int> q;
        
        for (const vector<int>& e: edges) {
            int u = e.front(),
                v = e.back();
            
            g[u].push_back(v);
            g[v].push_back(u);
            indeg[u]++;
            indeg[v]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 1) {
                q.push(i);
            }
        }
        
        while (not empty(q)) {
            int node = q.front();
            q.pop();
            
            indeg[node]--;
            long long addVal = 0;
            
            if (valuesll[node] % k == 0) {
                ans++;
            } else {
                addVal = valuesll[node];
            }
            
            for (const int& next: g[node]) {
                if (indeg[next] == 0) {
                    continue;
                }
                
                indeg[next]--;
                valuesll[next] += addVal;
                
                if (indeg[next] == 1) {
                    q.push(next);
                }
            }
        }
        
        return ans;
    }
};