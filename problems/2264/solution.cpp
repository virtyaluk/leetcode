class Solution {
public:
    string largestGoodInteger(string num) {
        char ch = '.';
        
        for (int i = 1; i < size(num) - 1; i++) {
            if (num[i] != num[i - 1] or num[i] != num[i + 1]) {
                continue;
            }
            
            ch = max(ch, num[i]);
        }
        
        if (ch == '.') {
            return "";
        }
        
        return string(3, ch);
    }
};