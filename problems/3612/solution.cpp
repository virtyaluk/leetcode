class Solution {
public:
    string processStr(string s) {
        string ans;

        for (const char& ch: s) {
            if (ch == '*') {
                if (not empty(ans)) {
                    ans.pop_back();
                }
            } else if (ch == '#') {
                ans += ans;
            } else if (ch == '%') {
                reverse(begin(ans), end(ans));
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};