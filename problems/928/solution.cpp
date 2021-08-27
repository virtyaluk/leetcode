class Solution {
private:
    int bfs(vector<vector<int>>& graph, vector<int>& initial, int node) {
        int ans = 0;
        queue<int> q;
        unordered_set<int> visited = {node};
        
        for (const int& i: initial) {
            if (i != node) {
                q.push(i);
            }
        }
        
        while (not empty(q)) {
            int nextNode = q.front();
            q.pop();
            
            if (visited.count(nextNode)) {
                continue;
            }
            
            visited.insert(nextNode);
            ans++;
            
            for (int i = 0; i < size(graph); i++) {
                if (i != nextNode and graph[nextNode][i]) {
                    q.push(i);
                }
            }
        }
        
        return ans;
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int ans = 0, n = size(initial), minCount = size(graph);
        
        sort(begin(initial), end(initial));
        
        for (const int& i: initial) {
            int cnt = bfs(graph, initial, i);
            
            if (cnt < minCount) {
                minCount = cnt;
                ans = i;
            }
        }
        
        return ans;
    }
};