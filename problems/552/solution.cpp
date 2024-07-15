const int MOD = 1e9 + 7;

class Solution {
public:
    int checkRecord(int n) {
        vector<long long> pl(n + 1),
            p(n + 1);
        
        pl[0] = p[0] = 1;
        pl[1] = 2;
        p[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            p[i] = pl[i - 1];
            pl[i] = (p[i] + p[i - 1] + p[i - 2]) % MOD;
        }
        
        long long ans = pl.back();
        
        for (int i = 0; i < n; i++) {
            long long tmp = (pl[i] * pl[n - i - 1]) % MOD;
            ans = (ans + tmp) % MOD;
        }
        
        return ans;
    }
};