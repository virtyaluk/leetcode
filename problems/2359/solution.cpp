class Solution {
private:
    void bfs(vector<int>& edges, int src, vector<int>& dist) {
        int n = size(edges);
        vector<bool> vis(n);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while (not empty(q)) {
            int node = q.front();
            q.pop();
            
            if (vis[node]) {
                continue;
            }

            vis[node]=true;
            int nebr=edges[node];
            
            if (nebr != -1 and not vis[nebr]) {
                q.push(nebr);
                dist[nebr] = 1 + dist[node];
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = size(edges),
            minTillNow = 1e9,
            ans = -1;
        vector<int> dist1(n, 1e9),
            dist2(n, 1e9);
        
        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);
        
        for (int i = 0; i < n; i++) {
            if (minTillNow > max(dist1[i], dist2[i])) {
                minTillNow = max(dist1[i], dist2[i]);
                ans = i;
            }
        }

        return ans;
    }
};