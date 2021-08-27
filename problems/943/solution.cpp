class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        string ans;
        int n = words.size();
        vector<vector<int>> overlaps(n, vector<int>(n)),
            dp(1 << n, vector<int>(n)),
            parent(1 << n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int m = min(words[i].size(), words[j].size());
                
                for (int k = m; k >= 0; k--) {
                    if (words[i].find(words[j].substr(0, k), words[i].size() - k) != string::npos) {
                        overlaps[i][j] = k;
                        break;
                    }
                }
            }
        }
        
        for (int mask = 0; mask < (1 << n); mask++) {
            parent[mask].assign(n, -1);
            
            for (int bit = 0; bit < n; bit++) {
                if (((mask >> bit) & 1) > 0) {
                    int pmask = mask ^ (1 << bit);
                    
                    if (pmask == 0) {
                        continue;
                    }
                    
                    for (int i = 0; i < n; i++) {
                        if (((pmask >> i) & 1) > 0) {
                            int val = dp[pmask][i] + overlaps[i][bit];
                            
                            if (val > dp[mask][bit]) {
                                dp[mask][bit] = val;
                                parent[mask][bit] = i;
                            }
                        }
                    }
                }
            }
        }
        
        vector<int> perm(n);
        vector<bool> seen(n);
        int t = 0, mask = (1 << n) - 1, p = 0;
        
        for (int j = 0; j < n; j++) {
            if (dp[(1 << n) - 1][j] > dp[(1 << n) - 1][p]) {
                p = j;
            }
        }
        
        while (p != -1) {
            perm[t++] = p;
            seen[p] = true;
            
            int p2 = parent[mask][p];
            
            mask ^= 1 << p;
            p = p2;
        }
        
        for (int i = 0; i < t/2; i++) {
            int v = perm[i];
            perm[i] = perm[t - 1 - i];
            perm[t - 1 - i] = v;
        }
        
        for (int i = 0; i < n; i++) {
            if (not seen[i]) {
                perm[t++] = i;
            }
        }
        
        ans = words[perm[0]];
        
        for (int i = 1; i < n; i++) {
            int overlap = overlaps[perm[i - 1]][perm[i]];
            
            ans += words[perm[i]].substr(overlap);
        }
        
        return ans;
    }
};