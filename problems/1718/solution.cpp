class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        if (n == 1) {
            return {1};
        }
        
        vector<int> ans(2 * (n - 1) + 1);
        vector<bool> visited(n);
        function<bool(int)> backtrack;
        
        ans[0] = ans[n] = n;
        backtrack = [&](int i) {
            if (i == ans.size()) {
                return true;
            }
            
            if (ans[i]) {
                return backtrack(i + 1);
            }
            
            for (int j = visited.size() - 1; j > 0; j--) {
                if (visited[j]) {
                    continue;
                }
                
                if (j != 1 && (i + j >= ans.size() || ans[i + j])) {
                    continue;
                }
                
                visited[j] = true;
                ans[i] = j;
                
                if (j != 1) {
                    ans[i + j] = j;
                }
                
                if (backtrack(i + 1)) {
                    return true;
                }
                
                if (j != 1) {
                    ans[i + j] = 0;
                }
                
                ans[i] = 0;
                visited[j] = false;
            }
            
            return false;
        };
        
        backtrack(1);
        
        return ans;
    }
};