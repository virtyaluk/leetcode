class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.size() - 1, len = 0;
        
        while (pos >= 0 && s[pos] == ' ') {
            pos--;
        }
        
        while (pos >= 0 && s[pos] != ' ') {
            pos--;
            len++;
        }
        
        return len;
    }
};