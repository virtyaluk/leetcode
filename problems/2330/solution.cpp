class Solution {
public:
    bool makePalindrome(string s) {
        int lo = 0, hi = size(s) - 1, dif = 0;
        
        while (lo <= hi) {
            dif += (s[lo++] != s[hi--]);
        }
        
        return dif <= 2;
    }
};