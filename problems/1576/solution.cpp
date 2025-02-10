class Solution {
public:
    string modifyString(string s) {
        for (int i = 0 ; i < size(s); i++) {
            if (s[i] != '?') {
                continue;
            }
            
            char left = i > 0 ? s[i - 1] : '.',
                right = i + 1 < size(s) ? s[i + 1] : '.',
                mid = '.';
            
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch != left and ch != right) {
                    mid = ch;
                    
                    break;
                }
            }
            
            s[i] = mid;
        }
        
        return s;
    }
};