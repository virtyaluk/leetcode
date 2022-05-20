const int MOD = 1e9 + 7;

class Solution {
private:
    int mask = 0;
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = size(hats);
        vector<vector<int>> dp(41, vector<int>(1 << n, -1));
        unordered_map<int, vector<int>> h2p;
        mask = (1 << n) - 1;
        
        for (int i = 0; i < size(hats); i++) {
            for (const int& h: hats[i]) {
                h2p[h].push_back(i);
            }
        }
        
        return dfs(dp, h2p, 0, 0);
    }
    
    int dfs(vector<vector<int>>& dp, unordered_map<int, vector<int>>& h2p, int hat, int people) {
        if (people == mask) {
            return 1;
        }
        
        if (hat > 40) {
            return 0;
        }
        
        if (dp[hat][people] != -1) {
            return dp[hat][people];
        }
        
        int ans = dfs(dp, h2p, hat + 1, people);
        
        for (const int& person: h2p[hat]) {
            if ((people >> person) & 1) {
                continue;
            }
            
            ans = (ans + dfs(dp, h2p, hat + 1, (1 << person) | people)) % MOD;
        }
        
        return dp[hat][people] = ans;
    }
};