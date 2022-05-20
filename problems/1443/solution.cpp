class Solution {
public:
    long dfs(int prev, int curr, vector<int> m[], vector<bool>& hasApple) {
        long ans = 0 ; 

        for (int child : m[curr]) {
            if (child != prev) {
                long cnt = dfs(curr, child, m, hasApple);

                if (cnt > 0 || hasApple[child]) {
                    ans += (cnt + 2);
                }
            }
        }

        return ans;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> m[n];
        
        for (const vector<int>& edge: edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }

        return dfs(-1, 0, m, hasApple);
    }
};