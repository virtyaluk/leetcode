class Solution {
public:
    void bfs(vector<int> &edges,int src,vector<int> &dist){
        int n=edges.size();
        queue<int> q;
        q.push(src);
        vector<bool> vis(n);

        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(vis[node]) continue;
            vis[node]=true;
            int nebr=edges[node];
            if(nebr!=-1 && !vis[nebr]){
                q.push(nebr);
                dist[nebr]=1+dist[node];
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,1e9);
        vector<int> dist2(n,1e9);
        bfs(edges,node1,dist1);
        bfs(edges,node2,dist2);
        int minTillNow=1e9,ans=-1;
        for(int i=0;i<n;i++){
            if(minTillNow>max(dist1[i],dist2[i])){
                minTillNow=max(dist1[i],dist2[i]);
                ans=i;
            }
        }
        return ans;
    }
};