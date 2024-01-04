class Solution {
private:
    void dfs(const vector<vector<int>>& requests, vector<int>& indegree, int i, int cnt, int& ans) {
        if (i >= size(requests)) {
            for (const int& degree: indegree) {
                if (degree) {
                    return;
                }
            }
            
            ans = max(ans, cnt);
            return;
        }
        
        vector<int> req = requests[i];
        
        indegree[req[0]]--;
        indegree[req[1]]++;
        
        dfs(requests, indegree, i + 1, cnt + 1, ans);
        
        indegree[req[0]]++;
        indegree[req[1]]--;
        
        dfs(requests, indegree, i + 1, cnt, ans);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> indegree(n);
        
        dfs(requests, indegree, 0, 0, ans);
        
        return ans;
    }
};