class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 0; i < size(s); i++) {
            if (not isdigit(s[i])) {
                continue;
            }
            
            s[i] = s[i - 1] + (s[i] - '0');
        }
        
        return s;
    }
};