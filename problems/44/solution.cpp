class Solution {
public:
    bool isMatch(string s, string p) {
        int m = size(s),
            n = size(p),
            i = 0,
            j = 0,
            pAllMathStart = -1,
            sAllMathStart = -1;
        
        while (i < m) {
            if (j < n and (p[j] == '?' or s[i] == p[j])) {
                i++;
                j++;
            } else if (j < n and p[j] == '*') {
                sAllMathStart = i;
                pAllMathStart = j++;
            } else if (pAllMathStart == -1) {
                return false;
            } else {
                j = pAllMathStart + 1;
                i = sAllMathStart + 1;
                sAllMathStart = i;
            }
        }
        
        while (j < n and p[j] == '*') {
            j++;
        }
        
        return j >= n;
    }
};