const int MOD = 1e9 + 7;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = size(target), m = size(words.front());
        unordered_map<int, unordered_map<char, int>> freq;
        vector<vector<long long int>> dp(n + 1, vector<long long int>(m + 1, -1));
        
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < size(words); j++) {
                freq[k][words[j][k]]++;
            }
        }
        
        return dfs(dp, freq, target, 0, 0);
    }
    
    int dfs(
        vector<vector<long long int>>& dp,
        unordered_map<int, unordered_map<char, int>>& freq,
        string& target,
        int idx,
        int x
    ) {
        if (idx >= size(target)) {
            return 1;
        }
        
        if (x >= size(freq)) {
            return 0;
        }
        
        if (dp[idx][x] != -1) {
            return dp[idx][x];
        }
        
        long long int ans = dfs(dp, freq, target, idx, x + 1) % MOD;
        
        if (freq[x].count(target[idx])) {
            long long int cnt = freq[x][target[idx]],
                tmp = dfs(dp, freq, target, idx + 1, x + 1) % MOD;
            
            ans = (ans + cnt * tmp) % MOD;
        }
        
        return dp[idx][x] = ans;
    }
};