class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        vector<bool> visited(n);
        vector<int> ids(n);
        unordered_map<int, unordered_set<int>> graph;
        function<void(int, int)> dfs;
        int idx = 0;
        
        dfs = [&](int at, int parent) {
            visited[at] = true;
            ids[at] = idx++;
            
            for (const int& to: graph[at]) {
                if (not visited[to]) {
                    dfs(to, at);
                }
            }
            
            if (parent != -1) {
                for (const int& to: graph[at]) {
                    if (to != parent) {
                        ids[at] = min(ids[at], ids[to]);
                    }
                }
                
                if (ids[at] > ids[parent]) {
                    ans.push_back({at, parent});
                }
            }
        };
        
        for (const vector<int>& e: connections) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (not visited[i]) {
                dfs(i, -1);
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> criticalConnections1(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        unordered_map<int, unordered_set<int>> graph;
        vector<bool> visited(n);
        vector<int> low(n), ids(n);
        function<void(int, int)> dfs;
        int id = 0;
        
        dfs = [&](int at, int parent) {
            visited[at] = true;
            ids[at] = low[at] = id++;
            
            for (const int& to: graph[at]) {
                if (to == parent) {
                    continue;
                } else if (!visited[to]) {
                    dfs(to, at);
                    low[at] = min(low[at], low[to]);
                    
                    if (ids[at] < low[to]) {
                        ans.push_back({at, to});
                    }
                } else {
                    low[at] = min(low[at], low[to]);
                }
            }
        };
        
        for (const vector<int>& e: connections) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
        
        return ans;
    }
};