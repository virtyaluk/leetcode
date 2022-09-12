class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    string labels;

    vector<int> dfs(int node, int par){
        vector<int> frq(26, 0);
        frq[labels[node] - 'a']++;
        
        for (auto& it: adj[node]) {
            if (it != par) {
                vector<int> v = dfs(it, node);
    
                for (int i = 0 ; i < 26; i++) {
                    frq[i] += v[i];
                }
            }
        }
        
        ans[node] += frq[labels[node] - 'a'];

        return frq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        labels = s;
        adj.resize(n);
        ans.resize(n,0);
        
        for (auto& it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(0, 0);

        return ans;
    }
};