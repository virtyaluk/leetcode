class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (size(palindrome) == 1) {
            return "";
        }
        
        for (int i = 0; i < size(palindrome) / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                
                return palindrome;
            }
        }
        
        palindrome.back() = 'b';
        
        return palindrome;
    }
};