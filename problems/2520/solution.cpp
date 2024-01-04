class Solution {
public:
    int countDigits(int num) {
        int ans = 0,
            x = num;
        
        while (x) {
            ans += (num % (x % 10)) == 0;
            x /= 10;
        }
        
        return ans;
    }
};