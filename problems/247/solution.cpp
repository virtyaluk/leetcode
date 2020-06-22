class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        unordered_map<string, string> um = {
            {"0", "0"},
            {"1", "1"},
            {"6", "9"},
            {"8", "8"},
            {"9", "6"}
        };
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"0", "1", "8"};
        
        if (n == 1) {
            return dp[n];
        }
        
        dp[2] = {"11", "69", "88", "96"};
        
        if (n == 2) {
            return dp[n];
        }
        
        dp[2].push_back("00");
        
        for (int idx = 3; idx <= n; idx++) {
            for (auto [ls, rs]: um) {
                if (ls == "0" and idx == n) {
                    continue;
                }
                
                for (int i = 0; i < size(dp[idx - 2]); i++) {
                    dp[idx].push_back(ls + dp[idx - 2][i] + rs);
                }
            }
        }
        
        return dp.back();
    }
    
    vector<string> findStrobogrammatic1(int n) {
        return helper(n, n);
    }
    
    vector<string> helper(int n, int origN) {
        if (n == 0) {
            return {""};
        }

        if (n == 1) {
            return {"0", "1", "8"};
        }
        
        vector<string> cands = helper(n - 2, n), ans;
        
        for (const string& cand: cands) {
            if (n != origN) {
                ans.push_back("0" + cand + "0");
            }
            
            ans.push_back("1" + cand + "1");
            ans.push_back("6" + cand + "9");
            ans.push_back("8" + cand + "8");
            ans.push_back("9" + cand + "6");
        }
        
        return ans;
    }
};