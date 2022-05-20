class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) {
            return 0;
        } else if (isPalindrome(s)) {
            return 1;
        }
        
        return 2;
    }
    
    bool isPalindrome(const string& s) {
        int lo = 0, hi = s.size() - 1;
        
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return false;
            }
            
            lo++;
            hi--;
        }
        
        return true;
    }
};