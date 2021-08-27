class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = size(graph);
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(2))),
            outdegree(n, vector<vector<int>>(n, vector<int>(2)));
        queue<vector<int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                outdegree[i][j][0] = size(graph[j]);
                outdegree[i][j][1] = size(graph[i]);
                
                for (const int& k: graph[i]) {
                    if (k == 0) {
                        outdegree[i][j][1]--;
                        
                        break;
                    }
                }
            }
        }
        
        for (int k = 1; k < n; k++) {
            for (int m = 0; m < 2; m++) {
                color[k][0][m] = 1;
                q.push({k, 0, m, 1});
                color[k][k][m] = 2;
                q.push({k, k, m, 2});
            }
        }
        
        while (not empty(q)) {
            vector<int> cur = q.front();
            q.pop();
            
            int cat = cur[0], mouse = cur[1], mouseMove = cur[2], c = cur[3];
            
            if (cat == 2 and mouse == 1 and mouseMove == 0) {
                return c;
            }
            
            int prevMouseMove = 1 - mouseMove;
            
            for (int prev: graph[prevMouseMove == 1 ? cat : mouse]) {
                int prevCat = prevMouseMove == 1 ? prev : cat,
                    prevMouse = prevMouseMove == 1 ? mouse : prev;
                
                if (prevCat == 0) {
                    continue;
                }
                
                if (color[prevCat][prevMouse][prevMouseMove] > 0) {
                    continue;
                }
                
                if (prevMouseMove == 1 and c == 2 or prevMouseMove == 0 and c == 1
                   or --outdegree[prevCat][prevMouse][prevMouseMove] == 0) {
                    color[prevCat][prevMouse][prevMouseMove] = c;
                    q.push({prevCat, prevMouse, prevMouseMove, c});
                }
            }
        }
        
        return color[2][1][0];
    }
};