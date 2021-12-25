class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> probs(n, 0.0);
        vector<pair<int, double>> g[n];
        queue<int> q;
        
        q.push(start);
        probs[start] = 1.0;
        
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            
            g[u].push_back({v, prob});
            g[v].push_back({u, prob});
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto [nextNode, prob]: g[node]) {
                if (probs[node] * prob > probs[nextNode]) {
                    q.push(nextNode);
                    probs[nextNode] = probs[node] * prob;
                }
            }
        }
        
        return probs[end];
    }
};