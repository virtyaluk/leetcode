class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = size(target), m = 1 << n;
        vector<uint> dp(m, -1);
        
        dp[0] = 0;
        
        for (int i = 0; i < m; i++) {
            if (dp[i] == -1) {
                continue;
            }
            
            for (const string& sticker: stickers) {
                int mask = i;
                
                for (const char& ch: sticker) {
                    for (int j = 0; j < n; j++) {
                        if (target[j] == ch and not (mask & (1 << j))) {
                            mask |= 1 << j;
                            break;
                        }
                    }
                }
                
                dp[mask] = min(dp[mask], dp[i] + 1);
            }
        }
        
        return dp.back();
    }
    
    int minStickers1(vector<string>& stickers, string target) {
        int m = size(stickers);
        vector<vector<int>> freq(m, vector<int>(26));
        unordered_map<string, int> dp = {{"", 0}};
        
        for (int i = 0; i < m; i++) {
            for (const char& ch: stickers[i]) {
                freq[i][ch - 'a']++;
            }
        }
        
        return dfs(freq, dp, target);
    }
    
    int dfs(const vector<vector<int>>& freq, unordered_map<string, int>& dp, string target) {
        if (dp.count(target)) {
            return dp[target];
        }
        
        int ans = INT_MAX, m = freq.size();
        vector<int> tfreq(26);
        
        for (const char& ch: target) {
            tfreq[ch - 'a']++;
        }
        
        for (int i = 0; i < m; i++) {
            if (not freq[i][target[0] - 'a']) {
                continue;
            }
            
            string nextTarget;
            
            for (int j = 0; j < 26; j++) {
                if (tfreq[j] - freq[i][j] > 0) {
                    nextTarget += string(tfreq[j] - freq[i][j], 'a' + j);
                }
            }
            
            if (nextTarget == target) {
                continue;
            }
            
            int cur = dfs(freq, dp, nextTarget);
            
            if (cur != -1) {
                ans = min(ans, cur + 1);
            }
        }
        
        dp[target] = ans == INT_MAX ? -1 : ans;
        return dp[target];
    }
};