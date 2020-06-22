class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(begin(envelopes), end(envelopes), [](vector<int>& lhs, vector<int>& rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1];
            }
            
            return lhs[0] < rhs[0];
        });
        
        vector<int> dp;
        
        for (vector<int>& e: envelopes) {
            auto it = lower_bound(begin(dp), end(dp), e[1]);
            
            if (it == dp.end()) {
                dp.push_back(e[1]);
            } else if (*it > e[1]) {
                *it = e[1];
            }
        }
        
        return dp.size();
    }
    
    int maxEnvelopes1(vector<vector<int>>& envelopes) {
        int ans = 1;
        vector<int> dp(envelopes.size());
        dp[0] = 1;
        
        sort(begin(envelopes), end(envelopes), [](vector<int>& lhs, vector<int>& rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] < rhs[1];
            }
            
            return lhs[0] < rhs[0];
        });
        
        for (int i = 1; i < envelopes.size(); i++) {
            dp[i] = 1;
            
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1] and dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};