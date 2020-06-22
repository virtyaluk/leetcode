class Solution {
public:
    bool canWin(string s) {
        for (int i = 1; i < size(s); i++) {
            if (s[i] == '+' and s[i - 1] == '+') {
                s[i] = s[i - 1] = '-';
                
                if (not canWin(s)) {
                    return true;
                }
                
                s[i] = s[i - 1] = '+';
            }
        }
        
        return false;
    }
};