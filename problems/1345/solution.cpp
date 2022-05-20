class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), ans = 0;;
        
        if (n <= 1) {
            return 0;
        }
        
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            graph[arr[i]].push_back(i);
        }
        
        q.push(0);
        
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                int node = q.front();
                q.pop();
                
                if (node == n - 1) {
                    return ans;
                }
                
                for (int& child: graph[arr[node]]) {
                    if (visited.find(child) == visited.end()) {
                        visited.insert(child);
                        q.push(child);
                    }
                }
                
                graph[arr[node]].clear();
                
                if (node + 1 < n && visited.find(node + 1) == visited.end()) {
                    visited.insert(node + 1);
                    q.push(node + 1);
                }
                
                if (node - 1 >= 0 && visited.find(node - 1) == visited.end()) {
                    visited.insert(node - 1);
                    q.push(node - 1);
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};