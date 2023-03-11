const int MOD = 1e9 + 7;

class Solution {
public:
    int countDistinctStrings(string s, int k) {
        int ans = 1, n = size(s);
        
        while (k <= n) {
            ans = (ans << 1) % MOD;
            n--;
        }
        
        return ans;
    }
};