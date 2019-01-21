class Solution {
public:
    bool isNumber(string s) {
        bool seenDot = false, seenEpsilon = false, seenDigit = false;
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            
            if (ch == '-' or ch == '+') {
                if (i > 0 and s[i - 1] != 'e' and s[i - 1] != 'E') {
                    return false;
                }
            } else if (ch == '.') {
                if (seenDot or seenEpsilon) {
                    return false;
                }
                
                seenDot = true;
            } else if (ch == 'e' or ch == 'E') {
                if (seenEpsilon or not seenDigit) {
                    return false;
                }
                
                seenEpsilon = true;
                seenDigit = false;
            } else if (isdigit(ch)) {
                seenDigit = true;
            } else {
                return false;
            }
        }
        
        return seenDigit;
    }
};