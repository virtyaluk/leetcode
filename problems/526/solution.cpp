class Solution {
public:
    int countArrangement(int n) {
        int ans = 0;
        vector<bool> visited(n + 1);
        
        backtrack(n, 1, visited, ans);
        
        return ans;
    }
    
    void backtrack(int& n, int pos, vector<bool>& visited, int& ans) {
        if (pos > n) {
            ans++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
            
                backtrack(n, pos + 1, visited, ans);

                visited[i] = false;
            }
        }
    }
};