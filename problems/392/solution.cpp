class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        
        for (const char& ch: t) {
            if (i == size(s)) {
                break;
            }
            
            if (s[i] == ch) {
                i++;
            }
        }
        
        return i == size(s);
    }
};