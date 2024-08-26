class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n + 1),
            dist(n + 1, vector<int>(2, INT_MAX));
        queue<pair<int, int>> q;
        int ans = 0;
        
        dist[1][0] = 0;
        q.push({1, 0});
        
        for (const vector<int>& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        while (not empty(q)) {
            auto [cur, curDist] = q.front();
            q.pop();

            for (int next : g[cur]) {
                int newDist = curDist + 1;
                
                if (newDist < dist[next][0]) {
                    dist[next][1] = dist[next][0];
                    dist[next][0] = newDist;
                    
                    q.push({next, newDist});
                } else if (newDist > dist[next][0] and newDist < dist[next][1]) {
                    dist[next][1] = newDist;
                    
                    q.push({next, newDist});
                }
            }
        }

        for (int i = 0; i < dist[n][1]; i++) {
            if ((ans / change) % 2 == 1) {
                ans = (ans / change + 1) * change;
            }
            
            ans += time;
        }

        return ans;
    }
};