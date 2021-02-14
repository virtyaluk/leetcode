const int MOD = 1e9 + 7;

class Solution {
public:
    int numTilings(int n) {
        vector<vector<long long int>> memo(n + 1, vector<long long int>(4, -1));
    
        return dp(memo, 0, true, true);
    }
    
    int getState(bool t1, bool t2) {
//         if (not t1 and not t2) {
//             return 0;
//         } else if (t1 and not t2) {
//             return 1;
//         } else if (not t1 and t2) {
//             return 2;
//         }
        
//         return 3;
        int state = 0;
        
//         if (t1) {
//             state |= 1;
//         }
        
//         if (t2) {
//             state |= 2;
//         }
        state |= t1 ? 1 : 0;
        state |= t2 ? 2 : 0;
        
        return state;
    }
    
    long long int dp(vector<vector<long long int>>& memo, int i, bool t1, bool t2) {
        int n = size(memo) - 1;
        
        if (i == n) {
            return 1;
        }
        
        long long int ans = 0;
        int state = getState(t1, t2);
        bool t3 = i + 1 < n, t4 = i + 1 < n;
        
        if (memo[i][state] != -1) {
            return memo[i][state];
        }
        
        // |‾
        if (t1 and t2 and t3) {
            ans += dp(memo, i + 1, false, true);
        }
        
        // |_
        if (t1 and t2 and t4) {
            ans += dp(memo, i + 1, true, false);
        }
        
        // ‾|
        if (t1 and not t2 and t3 and t4) {
            ans += dp(memo, i + 1, false, false);
        }
        
        // _|
        if (not t1 and t2 and t3 and t4) {
            ans += dp(memo, i + 1, false, false);
        }
        
        // |
        if (t1 and t2) {
            ans += dp(memo, i + 1, true, true);
        }
        
        // =
        if (t1 and t2 and t3 and t4) {
            ans += dp(memo, i + 1, false, false);
        }
        
        // ‾
        if (t1 and not t2 and t3) {
            ans += dp(memo, i + 1, false, true);
        }
        
        // _
        if (not t1 and t2 and t4) {
            ans += dp(memo, i + 1, true, false);
        }
        
        // next col
        if (not t1 and not t2) {
            ans += dp(memo, i + 1, true, true);
        }
        
        return memo[i][state] = ans % MOD;
    }
    
    int numTilings2(int n) {
        if (n <= 1) {
            return 1;
        }
        
        if (n == 2) {
            return 2;
        }
        
        deque<long long int> dq = {1, 1, 2};
        
        for (int i = 3; i <= n; i++) {
            dq.push_back((dq.back() * 2 + dq.front()) % MOD);
            dq.pop_front();
        }
        
        return dq.back();
    }
    
    int numTilings1(int n) {
        vector<long long int> dp(max(n, 2) + 1, 1);
        // dp[0] = 1;
        // dp[1] = 1;
        dp[2] = 2;
        // dp[3] = 5; // dp[i] = dp[i - 1] * 2 + dp[i - 3];
        
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD;
        }
        
        return dp[n];
    }
};