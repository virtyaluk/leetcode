struct Edge {
    int idx, to, cost;
    
    Edge(int idx, int to, int cost): idx(idx), to(to), cost(cost) {}
    
    bool operator < (const Edge& other) const {
        return cost > other.cost;
    }
};

class Solution {
private:
    int mstCost(vector<vector<Edge>>& graph, int startEdgeIdx, int startEdgeFrom, int ignoreEdgeIdx) {
        int cnt = 0, total = 0;
        vector<bool> visited(size(graph));
        priority_queue<Edge> pq;
        
        pq.emplace(-1, startEdgeFrom, 0);
        
        while (not empty(pq)) {
            auto [idx, to, cost] = pq.top();
            pq.pop();
            
            if (visited[to]) {
                continue;
            }
            
            visited[to] = true;
            cnt++;
            total += cost;
            
            if (cnt == size(graph)) {
                break;
            }
            
            for (Edge edge: graph[to]) {
                if (visited[edge.to] or edge.idx == ignoreEdgeIdx) {
                    continue;
                }
                
                if (edge.idx == startEdgeIdx) {
                    total += edge.cost;
                    edge.cost = 0;
                }
                
                pq.push(edge);
            }
        }
        
        return cnt == size(graph) ? total : INT_MAX;
    }
    
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(2);
        vector<vector<Edge>> graph(n);
        
        for (int i = 0; i < size(edges); i++) {
            graph[edges[i][0]].emplace_back(i, edges[i][1], edges[i][2]);
            graph[edges[i][1]].emplace_back(i, edges[i][0], edges[i][2]);
        }
        
        int curMstCost = mstCost(graph, -1, 0, -1);
        
        for (int i = 0; i < size(edges); i++) {
            if (mstCost(graph, i, edges[i][0], -1) > curMstCost) {
                continue;
            }
            
            if (mstCost(graph, -1, 0, i) > curMstCost) {
                ans[0].push_back(i);
            } else {
                ans[1].push_back(i);
            }
        }
        
        return ans;
    }
};