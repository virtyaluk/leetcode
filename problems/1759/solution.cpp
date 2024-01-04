const int MOD = 1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
        int ans = 0;
        
        for (int i = 0, theSame = 0; i < size(s); i++) {
            if (i > 0 and s[i] == s[i - 1]) {
                theSame++;
            } else {
                theSame = 1;
            }
            
            ans = (ans + theSame) % MOD;
        }
        
        return ans % MOD;
    }
};