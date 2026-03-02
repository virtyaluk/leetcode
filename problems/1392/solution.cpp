class Solution {
private:
    void helper(vector<int>& lps, string s, int n) {
        int len = 0,
            i = 1;
        
        while (i < n) {
            if (s[len] == s[i]) {
                len++;
                lps[i] = len;
                i++;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = len;
                i++;
            }
        }
    }
public:
    string longestPrefix(string s) {
        int n = size(s);
        vector<int> lps(n, 0);

        if (empty(s)) {
            return "";
        }

        helper(lps, s, n);

        return s.substr(0, lps[n - 1]);
    }
};