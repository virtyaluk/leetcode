class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }
        
        return helper(graph, informTime, headID);
    }
    
    int helper(vector<vector<int>>& g, const vector<int>& it, const int id) {
        int ans = 0;
        
        for (const int& nid: g[id]) {
            ans = max(ans, helper(g, it, nid));
        }
        
        return ans + it[id];
    }
};