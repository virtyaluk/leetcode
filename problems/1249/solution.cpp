class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int open = 0;
        
        for (char& ch: s) {
            if (ch == '(') {
                open++;
            } else if (ch == ')') {
                if (open) {
                    open--;
                } else {
                    ch = '.';
                }
            }
        }
        
        open = 0;
        
        for (int i = size(s) - 1; i >= 0; i--) {
            if (s[i] == ')') {
                open++;
            } else if (s[i] == '(') {
                if (open) {
                    open--;
                } else {
                    s[i] = '.';
                }
            }
        }
        
        for (const char& ch: s) {
            if (ch != '.') {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};