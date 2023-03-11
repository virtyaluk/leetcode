class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = size(s),
            n = size(t),
            i = 0,
            j = 0;
        
        while (i < m and j < n) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        
        return n - j;
    }
};