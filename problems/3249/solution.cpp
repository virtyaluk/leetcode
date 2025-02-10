class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        vector<int> counts = {-1};
        int n = size(edges) + 1,
            ans = 0;
        
        for (const vector<int>& e : edges){
            g[e.front()].push_back(e.back());
            g[e.back()].push_back(e.front());
            counts.push_back(-1);
        }
        
        for (int i = 0; i < n; i++) {
            if (counts[i] == -1) {
                dfs(g, counts, i, ans);
            }
        }
        return ans;
    }
private:
    int dfs(unordered_map<int, vector<int>>& g, vector<int>& counts, int root, int& res){
        if (counts[root] != -1) {
            return counts[root];
        }

        int ans = 0,
            size = -1;
        bool equal = true;
        counts[root] = 0;
        
        for (int next: g[root]) {
            if (counts[next] != -1) {
                continue;
            }
            
            int n = dfs(g, counts, next, res);
            ans += n;
            
            if (size == -1) {
                size = n;
            } else if (n != size) {
                equal = false;
            }
        }
        
        if (equal) {
            res++;
        }
        
        counts[root] = ans;
        
        return ans + 1;
    }
};