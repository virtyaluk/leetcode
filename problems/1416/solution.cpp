const int MOD = 1e9 + 7;

class Solution {
private:
    int dfs(vector<int>& dp, const string& s, int i, int k) {
        if (dp[i]) {
            return dp[i];
        }
        
        if (i == size(s)) {
            return 1;
        }
        
        if (s[i] == '0') {
            return 0;
        }
        
        int ans = 0;
        
        for (int j = i; j < size(s); j++) {
            long long int curNum = stoll(s.substr(i, j + 1 - i));
            
            if (curNum > k) {
                break;
            }
            
            ans = (ans + dfs(dp, s, j + 1, k)) % MOD;
        }
        
        return dp[i] = ans;
    }
public:
    int numberOfArrays(string s, int k) {
        int m = size(s);
        vector<int> dp(m + 1);
        
        return dfs(dp, s, 0, k);
    }
};