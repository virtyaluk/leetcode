class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr.empty() || start > arr.size()) {
            return false;
        }
        
        bool ans = false;
        vector<bool> visited(arr.size());
        function<void(int)> dfs;
        
        dfs = [&](int idx) {
            if (ans || idx < 0 || idx >= arr.size() || visited[idx]) {
                return;
            }
            
            if (arr[idx] == 0) {
                ans = true;
                return;
            }
            
            visited[idx] = true;
            
            dfs(idx + arr[idx]);
            dfs(idx - arr[idx]);
            
            visited[idx] = false;
        };
        
        dfs(start);
        
        return ans;
    }
};