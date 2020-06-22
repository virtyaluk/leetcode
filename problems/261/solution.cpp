class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> g;
        unordered_set<int> seen;
        queue<pair<int, int>> q;
        
        for (const vector<int>& edge: edges) {
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        
        q.push({0, -1});
        seen.insert(0);
        
        while (not empty(q)) {
            auto [curNode, parentNode] = q.front();
            q.pop();
            
            for (const int& nextNode: g[curNode]) {
                if (nextNode == parentNode) {
                    continue;
                }
                
                if (seen.count(nextNode)) {
                    return false;
                }
                
                seen.insert(nextNode);
                q.push({nextNode, curNode});
            }
        }
        
        return size(seen) == n;
    }
};