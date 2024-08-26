class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> g(n + 1);
        vector<int> indeg(n + 1),
            order;
        queue<int> q;
        
        for (const vector<int>& e: edges) {
            g[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        
        while (not empty(q)) {
            int cur = q.front();
            q.pop();
            
            order.push_back(cur);
            
            n--;
            
            for (const int& next: g[cur]) {
                if (--indeg[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if (n != 0) {
            return {};
        }
        
        return order;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rows = topoSort(rowConditions, k),
            cols = topoSort(colConditions, k);
        vector<vector<int>> ans(k, vector<int>(k));
        
        if (empty(rows) or empty(cols)) {
            return {};
        }
        
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rows[i] == cols[j]) {
                    ans[i][j] = rows[i];
                }
            }
        }
        
        return ans;
    }
};