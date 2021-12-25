class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        int ans = 0;
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        queue<int> q;
        
        for (const vector<int> e: relations) {
            int u = e[0] - 1, v = e[1] - 1;
            
            g[u].push_back(v);
            indegree[v]++;
        }
        
        for (int i = 0; i < indegree.size(); i++) {
            if (not indegree[i]) {
                q.push(i);
            }
        }
        
        while (not q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                for (const int& next: g[q.front()]) {
                    if (not --indegree[next]) {
                        q.push(next);
                    }
                }
                
                q.pop();
            }
            
            ans++;
        }
        
        if (any_of(begin(indegree), end(indegree), [](const int& node) {
            return node;
        })) {
            return -1;
        }
        
        return ans;
    }
};