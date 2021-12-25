class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int, vector<pair<int, bool>>> g;
        vector<int> ans(n);
        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int, bool>> q;
        
        for (int i = 0; i < size(redEdges); i++) {
            g[redEdges[i][0]].push_back({redEdges[i][1], true});
        }
        
        for (int i = 0; i < size(blueEdges); i++) {
            g[blueEdges[i][0]].push_back({blueEdges[i][1], false});
        }
        
        dist[0] = {0, 0};
        q.push({0, true});
        q.push({0, false});
        
        while (not empty(q)) {
            auto [node, isRed] = q.front();
            q.pop();
            
            for (auto [nextNode, nextIsRed]: g[node]) {
                if (isRed == nextIsRed or dist[nextNode][nextIsRed] != -1) {
                    continue;
                }
                
                dist[nextNode][nextIsRed] = 1 + dist[node][isRed];
                
                q.push({nextNode, nextIsRed});
            }
        }
        
        for (int i = 1; i < n; i++) {
            int red = dist[i][0],
                blue = dist[i][1],
                m = min(red, blue),
                M = max(red, blue);
            
            ans[i] = m != -1 ? m : M;
        }
        
        return ans;
    }
};