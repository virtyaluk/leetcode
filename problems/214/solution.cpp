class Solution {
public:
    string shortestPalindrome(string s) {
        int n = size(s), i = 0;
        
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                i++;
            }
        }
        
        if (i == n) {
            return s;
        }
        
        string pref = s.substr(i, n);
        
        reverse(begin(pref), end(pref));
        
        return pref + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};