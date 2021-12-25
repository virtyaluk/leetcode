class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        unordered_map<int, unordered_set<int>> g;
        
        for (int i = 0; i < size(parent); i++) {
            g[parent[i]].insert(i);
        }
        
        return dfs(value, g, 0).second;
    }
    
    pair<int, int> dfs(vector<int>& value, unordered_map<int, unordered_set<int>>& g, int idx) {
        int totalSum = value[idx],
            nodesCount = 1;
        
        for (const int& next: g[idx]) {
            auto [nextSum, nextCount] = dfs(value, g, next);
            totalSum += nextSum;
            nodesCount += nextCount;
        }
        
        if (not totalSum) {
            nodesCount = 0;
        }
        
        return {totalSum, nodesCount};
    }
};