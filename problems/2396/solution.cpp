class Solution {
private:
    bool isPalindrome(string str) {
        int lo = 0, hi = size(str) - 1;
        
        while (lo <= hi) {
            if (str[lo++] != str[hi--]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool check(int n, int base) {
        string str = "";

        while (n) {
            str += to_string(n % base);
            n /= base;
        }
        
        return isPalindrome(str);
    }
public:
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++) {
            if (not check(n, i)) {
                return false;
            }
        }
        
        return true;
    }
};