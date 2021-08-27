typedef long long int ll;
const int MOD = 1000000007;

class Solution {
private:
    vector<vector<int>> g = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};

public:
    int knightDialer(int n) {
        int ans = 0;   
        vector<vector<ll>> im(10, vector<ll>(10)), m = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}
        };
        
        for (int i = 0; i < im.size(); i++) {
            im[i][i] = 1;
        }
        
        n--;
        
        while (n) {
            if (n & 1) {
                im = matmul(m, im);
            }
            
            m = matmul(m, m);
            n /= 2;
        }
        
        for (const vector<ll>& row: im) {
            for (const ll& col: row) {
                ans = (ans + col) % MOD;
            }
        }
        
        return ans;
    }
    
    vector<vector<ll>> matmul(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
        int n = a.size();
        vector<vector<ll>> ans(n, vector<ll>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    ans[i][j] += a[i][k] * b[k][j] % MOD;
                    ans[i][j] %= MOD;
                }
            }
        }
        
        return ans;
    }
    
    int knightDialer3(int n) {
        vector<int> dp(10, 1);
        
        for (int i = 0; i < n - 1; i++) {
            vector<int> curDp(10);
            
            for (int j = 0; j < 10; j++) {
                for (const int& nb: g[j]) {
                    curDp[j] += dp[nb];
                    curDp[j] %= MOD;
                }
            }
            
            dp = curDp;
        }
        
        return accumulate(begin(dp), end(dp), 0, [](const int& init, const int& cur) {
            return (init + cur) % MOD;
        });
    }
    
    int knightDialer2(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(10));
        
        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                for (const int& nb: g[j]) {
                    dp[i][j] += dp[i - 1][nb];
                    dp[i][j] %= MOD;
                }
            }
        }
        
        return accumulate(begin(dp[n]), end(dp[n]), 0, [](const int& init, const int& cur) {
            return (init + cur) % MOD;
        });
    }
    
    int knightDialer1(int n) {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(10));
        
        for (int i = 0; i < 10; i++) {
            ans = (ans + helper(n - 1, i, dp)) % MOD;
        }
        
        return ans;
    }
    
    int helper(int n, int b, vector<vector<int>>& dp) {
        if (n == 0) {
            return 1;
        }
        
        if (dp[n][b]) {
            return dp[n][b];
        }
        
        int ans = 0;
        
        for (const int& nb: g[b]) {
            ans = (ans + helper(n - 1, nb, dp)) % MOD;
        }
        
        return dp[n][b] = ans;
    }
};