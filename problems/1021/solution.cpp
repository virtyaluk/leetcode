class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int start = 0, open = 0;
        
        for (int i = 0; i < size(s); i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                open--;
                
                if (open == 0) {
                    ans += s.substr(start + 1, i - start - 1);
                    start = i + 1;
                }
            }
        }
        
        return ans;
    }
};