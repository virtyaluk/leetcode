class Graph {
private:
    unordered_map<int, unordered_map<int, int>> g;
    int _n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        for (const vector<int>& e: edges) {
            int u = e[0],
                v = e[1],
                cost = e[2];
            
            g[u][v] = cost;
        }
        
        _n = n;
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]][edge[1]] = edge[2];
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> costs(_n, INT_MAX);
        costs[node1] = 0;
        pq.push({0, node1});
        
        while (not empty(pq)) {
            auto [cost, u] = pq.top();
            pq.pop();
            
            if (cost > costs[u]) {
                continue;
            }
            
            if (u == node2) {
                return cost;
            }
            
            for (auto [v, nextCost]: g[u]) {
                int newCost = cost + nextCost;
                
                if (newCost < costs[v]) {
                    costs[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */