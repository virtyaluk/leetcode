class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> g;
        vector<int> ans;
        
        for (const vector<int>& e: edges) {
            g[e[1]]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (not g[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};