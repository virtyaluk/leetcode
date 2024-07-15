class Solution {
private:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& d, int i, int start, int dist) {
        d[start][i] = dist;
        
        for (const int& next: g[i]) {
            if (d[start][next] == -1) {
                dfs(g, d, next, start, dist + 1);
            }
        }
    }
    
    int findClosest(vector<vector<int>>& g, vector<vector<int>>& d, int start, int end, int node, int ans) {
        for (const int& next: g[start]) {
            if (d[start][end] > d[next][end]) {
                return findClosest(g, d, next, end, node, d[ans][node] < d[next][node] ? ans : next);
            }
        }
        
        return ans;
    }
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        vector<vector<int>> g(n, vector<int>()),
            d(n, vector<int>(n, -1));
        
        for (const vector<int>& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        for (int i = 0; i < n; i++) {
            dfs(g, d, i, i, 0);
        }
        
        for (const vector<int>& q: query) {
            ans.push_back(findClosest(g, d, q[0], q[1], q[2], q[0]));
        }
        
        return ans;
    }
};