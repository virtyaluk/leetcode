class Solution {
public:
    bool validPalindrome(string s) {
        int lo = 0, hi = size(s) - 1;
        
        while (lo <= hi) {
            if (s[lo] != s[hi]) {
                return isPalindrome(s, lo + 1, hi) or isPalindrome(s, lo, hi - 1);
            }
            
            lo++;
            hi--;
        }
        
        return true;
    }
    
    bool isPalindrome(const string& s, int lo, int hi) {
        while (lo <= hi) {
            if (s[lo++] != s[hi--]) {
                return false;
            }
        }
        
        return true;
    }
};