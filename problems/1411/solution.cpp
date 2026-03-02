const int MOD = 1e9 + 7;

class Solution {
public:
    int numOfWays(int n) {
        long long aba = 6,
            abc = 6;
        
        for (int i = 2; i <= n; i++) {
            long long newAba = (3 * aba + 2 * abc) % MOD,
                newAbc = (2 * aba + 2 * abc) % MOD;
            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % MOD;
    }
};