class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int lo = 0, hi = size(s) - 1; lo < hi; lo++, hi--) {
            char nextChar = min(s[lo], s[hi]);
            s[lo] = s[hi] = nextChar;
        }
        
        return s;
    }
};