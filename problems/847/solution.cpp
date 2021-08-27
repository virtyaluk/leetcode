class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = size(graph);
        unordered_set<string> us; // bitMask_node
        queue<tuple<int, int, int>> q; // bitMask, node, cost
        
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            
            q.push({mask, i, 1});
            us.insert(to_string(mask) + "_" + to_string(i));
        }
        
        while (not empty(q)) {
            auto [mask, u, cost] = q.front();
            q.pop();
            
            if (mask == (1 << n) - 1) {
                return cost - 1;
            } else {
                for (int v: graph[u]) {
                    int newMask = mask | (1 << v);
                    string key = to_string(newMask) + "_" + to_string(v);
                    
                    if (not us.count(key)) {
                        us.insert(key);
                        q.push({newMask, v, cost + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};