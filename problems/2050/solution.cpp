class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, unordered_set<int>> g;
        vector<int> indegree(n), m(n);
        queue<int> q;
        
        for (const vector<int>& r: relations) {
            int u = r.front() - 1,
                v = r.back() - 1;
            
            g[u].insert(v);
            indegree[v]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (not indegree[i]) {
                q.push(i);
                m[i] = time[i];
            }
        }
        
        while (not empty(q)) {
            int u = q.front();
            q.pop();
            
            for (const int& v: g[u]) {
                m[v] = max(m[v], m[u] + time[v]);
                indegree[v]--;
                
                if (not indegree[v]) {
                    q.push(v);
                }
            }
        }
        
        return *max_element(begin(m), end(m));
    }
};