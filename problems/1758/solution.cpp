class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        
        for (int i = 0; i < size(s); i++) {
            if (i % 2 == 0) {
                if (s[i] == '1') {
                    ans++;
                }
            } else {
                if (s[i] == '0') {
                    ans++;
                }
            }
        }
        
        return min(ans, (int) size(s) - ans);
    }
};