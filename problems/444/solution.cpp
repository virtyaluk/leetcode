class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, int> indegree;
        queue<int> q;
        int i = 0;
        
        for (const vector<int>& seq: seqs) {
            for (const int& num: seq) {
                indegree[num] = 0;
            }
        }
        
        for (const vector<int>& seq: seqs) {
            for (int i = 0; i < seq.size() - 1; i++) {
                int u = seq[i], v = seq[i + 1];
                
                if (not graph[u].count(v)) {
                    graph[u].insert(v);
                    indegree[v]++;
                }
            }
        }
        
        if (indegree.size() != org.size()) {
            return false;
        }
        
        for (auto &[u, deg]: indegree) {
            if (not deg) {
                q.push(u);
            }
        }
        
        while (not q.empty()) {
            if (q.size() > 1) {
                return false;
            }
            
            int u = q.front();
            q.pop();
            
            if (i < org.size() and org[i] == u) {
                i++;
            }
            
            for (const int& next: graph[u]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return i >= org.size();
    }
};