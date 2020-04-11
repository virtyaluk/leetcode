class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0, hi = size(s) - 1;
        
        while (lo <= hi) {
            if (not isalnum(s[lo])) {
                lo++;
                continue;
            }
            
            if (not isalnum(s[hi])) {
                hi--;
                continue;
            }
            
            if (tolower(s[lo++]) != tolower(s[hi--])) {
                return false;
            }
        }
        
        return true;
    }
};