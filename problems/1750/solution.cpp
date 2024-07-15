class Solution {
public:
    int minimumLength(string s) {
        int lo = 0,
            hi = size(s) - 1;
        
        while (lo < hi and s[lo] == s[hi]) {
            char ch = s[lo];
            
            while (lo <= hi and ch == s[lo]) {
                lo++;
            }
            
            while (hi > lo and ch == s[hi]) {
                hi--;
            }
        }
        
        return hi - lo + 1;
    }
};