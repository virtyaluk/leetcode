class Solution {
public:
    bool doesAliceWin(string s) {
        int ans = 0;
        
        for (const char& ch: s) {
            ans += ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
        }
        
        return ans > 0;
    }
};