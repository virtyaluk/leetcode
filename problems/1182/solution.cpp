class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = size(colors);
        vector<int> ans;
        vector<vector<int>> dists(3, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++) {
            for (int color = 1; color <= 3; color++) {
                if (color == colors[i]) {
                    dists[color - 1][i] = 0;
                } else if (i) {
                    dists[color - 1][i] = dists[color - 1][i - 1] == -1 ? -1 : 1 + dists[color - 1][i - 1];
                }
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int color = 1; color <= 3; color++) {
                if (color == colors[i]) {
                    dists[color - 1][i] = 0;
                } else if (i + 1 < n) {
                    int next = dists[color - 1][i + 1] == -1 ? -1 : 1 + dists[color - 1][i + 1];
                    
                    if (next != -1 and dists[color - 1][i] != -1) {
                        dists[color - 1][i] = min(dists[color - 1][i], next);
                    } else {
                        dists[color - 1][i] = max(dists[color - 1][i], next);
                    }
                }
            }
        }
        
        for (const vector<int> q: queries) {
            int i = q[0], c = q[1];
            
            ans.push_back(dists[c - 1][i]);
        }
        
        return ans;
    }
};