class Solution {
public:
    int takeCharacters(string s, int k) {
        int a = 0,
            b = 0,
            c = 0,
            ans = 0;
        
        for (const char& ch: s) {
            a += ch == 'a';
            b += ch == 'b';
            c += ch == 'c';
        }
        
        if (a < k or b < k or c < k) {
            return -1;
        }
        
        for (int lo = 0, hi = 0, a1 = 0, b1 = 0, c1 = 0; hi < size(s); hi++) {
            a1 += s[hi] == 'a';
            b1 += s[hi] == 'b';
            c1 += s[hi] == 'c';
            
            while (lo <= hi and (a - a1 < k or b - b1 < k or c - c1 < k)) {
                a1 -= s[lo] == 'a';
                b1 -= s[lo] == 'b';
                c1 -= s[lo] == 'c';
                lo++;
            }
            
            ans = max(ans, hi - lo + 1);
        }
        
        return size(s) - ans;
    }
};