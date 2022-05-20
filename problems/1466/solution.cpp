class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans = 0;
        unordered_map<int, unordered_set<int>> in, out;
        
        for (int i = 0; i < size(connections); i++) {
            out[connections[i][0]].insert(connections[i][1]);
            in[connections[i][1]].insert(connections[i][0]);
        }
        
        dfs(in, out, 0, ans);
        
        return ans;
    }
    
    void dfs(
        unordered_map<int, unordered_set<int>>& in,
        unordered_map<int, unordered_set<int>>& out,
        int node,
        int& ans
    ) {
        for (int nextNode: out[node]) {
            ans++;
            
            in[nextNode].erase(node);
            dfs(in, out, nextNode, ans);
        }
        
        for (int nextNode: in[node]) {
            out[nextNode].erase(node);
            dfs(in, out, nextNode, ans);
        }
    }
};