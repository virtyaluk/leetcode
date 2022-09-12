class Solution {
public:
    int findCenter1(vector<vector<int>>& edges) {
        int ans = -1;
        unordered_map<int, int> m;
        
        for (const vector<int>& e: edges) {
            int u = e[0], v = e[1];
            
            m[u]++;
            m[v]++;
            
            if (m[u] == edges.size()) {
                ans = u;
            }
            
            if (m[v] == edges.size()) {
                ans = v;
            }
        }
        
        return ans;
    }
    
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};