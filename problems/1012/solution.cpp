class Solution {
private:
    vector<int> nums;
    int dp[10][2][2][2][1 << 10];
    
public:
    int numDupDigitsAtMostN(int n) {
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        
        memset(dp, -1, sizeof(dp));
        reverse(begin(nums), end(nums));
        
        return dfs(0, 0, 0, 0, 0);
    }
    
    int dfs(int pos, int tight, int start, int rep, int mask) {
        if (pos >= size(nums)) {
            return rep;
        }
        
        if (dp[pos][tight][start][rep][mask] == -1) {
            int k = nums[pos],
                ans = 0;
            
            if (tight) {
                k = 9;
            }
            
            for (int i = 0; i <= k; i++) {
                int ns = start or i > 0,
                    nt = tight or i < k;
                
                if (ns) {
                    ans += dfs(pos + 1, nt, ns, rep || (mask & (1 << i)), mask | (1 << i));
                } else {
                    ans += dfs(pos + 1, nt, 0, rep, mask);
                }
            }
            
            dp[pos][tight][start][rep][mask] = ans;
        }
        
        return dp[pos][tight][start][rep][mask];
    }
};