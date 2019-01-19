class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversedX = 0;
        
        while (x > reversedX) {
            reversedX = reversedX * 10 + x % 10;
            x /= 10;
        }
        
        return x == reversedX || x == reversedX / 10;
    }
};