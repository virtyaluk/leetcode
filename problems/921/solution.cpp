class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0, open = 0;
        
        for (const char& ch: s) {
            if (ch == '(') {
                open++;
            } else if (ch == ')') {
                if (open) {
                    open--;
                } else {
                    ans++;
                }
            }
        }
        
        return ans + open;
    }
};