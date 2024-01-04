class Solution {
private:
    void dfs(const vector<int>& cookies, vector<int>& dp, int idx, int& ans) {
        if (idx >= size(cookies)) {
            ans = min(ans, *max_element(begin(dp), end(dp)));
            return;
        }
        
        for (int i = 0; i < size(dp); i++) {
            dp[i] += cookies[idx];
            
            dfs(cookies, dp, idx + 1, ans);
            
            dp[i] -= cookies[idx];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dp(k);
        int ans = INT_MAX;
        
        dfs(cookies, dp, 0, ans);
        
        return ans;
    }
};